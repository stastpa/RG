package thedrake;

import java.io.PrintWriter;
import java.util.*;

public class BoardTroops implements JSONSerializable{
	private final PlayingSide playingSide;
	private final Map<BoardPos, TroopTile> troopMap;
	private final TilePos leaderPosition;
	private final int guards;

	public BoardTroops(PlayingSide playingSide) { 

		this.troopMap = Collections.emptyMap();
		this.leaderPosition = TilePos.OFF_BOARD;
		this.guards = 0;
		this.playingSide = playingSide;
	}
	
	public BoardTroops(
			PlayingSide playingSide,
			Map<BoardPos, TroopTile> troopMap,
			TilePos leaderPosition, 
			int guards) {
		this.playingSide = playingSide;
		this.troopMap = troopMap;
		this.leaderPosition = leaderPosition;
		this.guards = guards;
	}

	public Optional<TroopTile> at(TilePos pos) {
		if(troopMap.containsKey(pos))
			return Optional.ofNullable(troopMap.get(pos));
		else
			return Optional.empty();
	}
	
	public PlayingSide playingSide() {
		return this.playingSide;
	}
	
	public TilePos leaderPosition() {
		if(isLeaderPlaced()){
			return leaderPosition;
		}
		else
			return TilePos.OFF_BOARD;
	}

	public int guards() {
		return this.guards;
	}
	
	public boolean isLeaderPlaced() {
		return leaderPosition != TilePos.OFF_BOARD;
	}
	
	public boolean isPlacingGuards() {
		return guards < 2 && isLeaderPlaced();
	}

	public Set<BoardPos> troopPositions() {
		Set<BoardPos> positions = new HashSet<>();

		for (Map.Entry<BoardPos, TroopTile> entry : troopMap.entrySet())
		{
			if (!troopMap.containsValue(Optional.empty()))
			{
				positions.add(entry.getKey());
			}
		}
		return positions;
	}

	public BoardTroops placeTroop(Troop troop, BoardPos target)
	{
		Map<BoardPos, TroopTile> newTroops = new HashMap<>(troopMap);

		if(newTroops.containsKey(target))
		{
			throw new IllegalArgumentException();
		}


		TroopTile tile = new TroopTile(troop, this.playingSide, TroopFace.AVERS);
		newTroops.put(target, tile);

		if(!isLeaderPlaced())
		{
			return new BoardTroops(playingSide(), newTroops, target, guards);
		}
		else  if(isPlacingGuards())
		return new BoardTroops(playingSide(), newTroops, leaderPosition, guards+1);
		else
			return new BoardTroops(playingSide(), newTroops, leaderPosition, guards);
	}
	
	public BoardTroops troopStep(BoardPos origin, BoardPos target)
	{ //TODO
		if(!isLeaderPlaced() || isPlacingGuards())
			throw new IllegalStateException();
		if(at(origin).isEmpty())
			throw new IllegalArgumentException();
		if(!at(target).isEmpty())
			throw new IllegalArgumentException();

		Map<BoardPos, TroopTile> newTroops = new HashMap<>(troopMap);
		TroopTile tile = newTroops.remove(origin);
		newTroops.put(target, tile.flipped());
		if(leaderPosition.equalsTo(origin.i(), origin.j())) // leader pos
		{
			return new BoardTroops(playingSide(), newTroops, target, guards);
		}
		else
		{
			return new BoardTroops(playingSide(), newTroops, leaderPosition, guards);
		}
	}
	
	public BoardTroops troopFlip(BoardPos origin) {
		if(!isLeaderPlaced()) {
			throw new IllegalStateException(
					"Cannot move troops before the leader is placed.");			
		}
		
		if(isPlacingGuards()) {
			throw new IllegalStateException(
					"Cannot move troops before guards are placed.");			
		}
		
		if(at(origin).isEmpty())
			throw new IllegalArgumentException();
		
		Map<BoardPos, TroopTile> newTroops = new HashMap<>(troopMap);
		TroopTile tile = newTroops.remove(origin);
		newTroops.put(origin, tile.flipped());

		return new BoardTroops(playingSide(), newTroops, leaderPosition, guards);
	}
	
	public BoardTroops removeTroop(BoardPos target) {
		if(!isLeaderPlaced() || isPlacingGuards())
		{
			throw new IllegalStateException();
		}
		if(at(target).isEmpty())
			throw new IllegalArgumentException();
		Map<BoardPos, TroopTile> newTroops = new HashMap<>(troopMap);

		if(leaderPosition.equalsTo(target.i(), target.j())) // leader pos
		{
			newTroops.remove(target);
			return new BoardTroops(playingSide(), newTroops, TilePos.OFF_BOARD, guards);
		}
		else
			newTroops.remove(target);
		return new BoardTroops(playingSide(), newTroops, leaderPosition, guards);
	}

	boolean ComparePos(BoardPos a, BoardPos b)
	{
		 if(a.j() < b.j())
		 {
			 return true;
		 }
		 else if(a.j() > b.j())
			 return false;
		 else if(a.j() == b.j())
		 {
			 if(a.i() < b.i())
			 {
				 return true;
			 }
			 else
				 return false;
		 }
		 return false;
	}

	@Override
	public void toJSON(PrintWriter writer) {
		writer.printf("{");
		writer.printf("\"side\":");
		playingSide.toJSON(writer);

		writer.printf(",");
		writer.printf("\"leaderPosition\":");
		leaderPosition.toJSON(writer);

		writer.printf(",\"guards\"" + ":" + guards + ",");
		writer.printf("\"troopMap\":");
		writer.printf("{");

		int troopCount = 0;

		ArrayList<BoardPos> troops = new ArrayList(troopMap.keySet());

		ArrayList tr2 = new ArrayList();

		for(BoardPos key : troops)
		{

			tr2.add(key.toString());
		}

		Collections.sort(tr2);
		BoardPos theOne = null;
		for(Object pos : tr2)
		{
			writer.printf("\"" + pos + "\"");
			writer.printf(":");

			for (BoardPos troop : troops) {
				if (Objects.equals(pos, troop.toString())) {
					theOne = troop;
				}
			}
			troopMap.get(theOne).toJSON(writer);
				troopCount+= 1;

			if(troopCount < troopMap.size())
			{
				writer.printf(",");
			}
		}
		writer.printf("}");
		writer.printf("}");
	}
}
