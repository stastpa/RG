package thedrake;

import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Army implements JSONSerializable{
	private final BoardTroops boardTroops;
	private final List<Troop> stack;
	private final List<Troop> captured;
	
	public Army(PlayingSide playingSide, List<Troop> stack) {
		this(
				new BoardTroops(playingSide), 
				stack, 
				Collections.emptyList());
	}
	
	public Army( 
			BoardTroops boardTroops,
			List<Troop> stack, 
			List<Troop> captured) {
		this.boardTroops = boardTroops;
		this.stack = stack;
		this.captured = captured;
	}
	
	public PlayingSide side() {
		return boardTroops.playingSide();
	}
	
	public BoardTroops boardTroops() {
		return boardTroops;
	}
	
	public List<Troop> stack() {
		return stack;
	}
	
	public List<Troop> captured() {
		return captured;
	}

	public Army placeFromStack(BoardPos target) {
		if(target == TilePos.OFF_BOARD) 
			throw new IllegalArgumentException();
		
		if(stack.isEmpty())
			throw new IllegalStateException();
		
		if(boardTroops.at(target).isPresent())
			throw new IllegalStateException();

		List<Troop> newStack = new ArrayList<Troop>(
				stack.subList(1, stack.size()));
		
		return new Army(
				boardTroops.placeTroop(stack.get(0), target),
				newStack, 
				captured);
	}
	
	public Army troopStep(BoardPos origin, BoardPos target) {
		return new Army(boardTroops.troopStep(origin, target), stack, captured);
	}
	
	public Army troopFlip(BoardPos origin) {
		return new Army(boardTroops.troopFlip(origin), stack, captured);
	}
	
	public Army removeTroop(BoardPos target) {
		return new Army(boardTroops.removeTroop(target), stack, captured);
	}
	
	public Army capture(Troop troop) {
		List<Troop> newCaptured = new ArrayList<Troop>(captured);
		newCaptured.add(troop);
		
		return new Army(boardTroops, stack, newCaptured);
	}

	@Override
	public void toJSON(PrintWriter writer) {
		writer.printf("{");

		writer.printf("\"boardTroops\":");
		boardTroops.toJSON(writer);

		writer.printf(",");
		writer.printf("\"stack\":");
		writer.printf("[");

		int troopcount = 0;
		for(Troop troop : stack())
		{
			troop.toJSON(writer);
			troopcount += 1;
			if(troopcount < stack().size())
			{
				writer.printf(",");
			}
		}
		writer.printf("]");

		writer.printf(",");
		writer.printf("\"captured\":");
		writer.printf("[");

		int capCount = 0;
		for(Troop troop : captured())
		{
			if(capCount != 0)
			{
				writer.printf(",");
			}
			capCount += 1;
			troop.toJSON(writer);

		}
		writer.printf("]");
		writer.printf("}");
	}
}
