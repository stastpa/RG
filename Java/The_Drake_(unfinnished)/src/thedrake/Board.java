package thedrake;


import java.io.PrintWriter;

import static thedrake.BoardTile.EMPTY;

public class Board implements JSONSerializable{
	private final BoardTile [][] playBoard;
	private final int dimension;

	// Konstruktor. Vytvoří čtvercovou hrací desku zadaného rozměru, kde všechny dlaždice jsou prázdné, tedy BoardTile.EMPTY
	public Board(int dimension) {
		this.dimension = dimension;
		this.playBoard = new BoardTile[dimension][dimension];
		for( int i = 0; i < dimension; i++)
		{
			for ( int j = 0; j < dimension; j++)
			{
				playBoard[i][j] = EMPTY;
			}
		}
	}

	// Rozměr hrací desky
	public int dimension() {
		return this.dimension;
	}

	// Vrací dlaždici na zvolené pozici.
	public BoardTile at(TilePos pos) {
		return playBoard[pos.i()] [pos.j()];
	}

	// Vytváří novou hrací desku s novými dlaždicemi. Všechny ostatní dlaždice zůstávají stejné
	public Board withTiles(TileAt ...ats) {
		Board clone = new Board(dimension);

		for(int i = 0; i < dimension; i++)
		{
			clone.playBoard[i] = this.playBoard[i].clone();
		}
		for(TileAt var : ats)
		{
			clone.playBoard[var.pos.i()][var.pos.j()] = var.tile;
		}
		return clone;
	}

	// Vytvoří instanci PositionFactory pro výrobu pozic na tomto hracím plánu
	public PositionFactory positionFactory() {
		return new PositionFactory(dimension);
	}

	@Override
    public void toJSON(PrintWriter writer) {
		writer.printf("{");
		writer.printf("\"dimension\""+ ":" + dimension);
		writer.printf(",");
		writer.printf("\"tiles\":");
		writer.printf("[");


		for(int j = 0; j < dimension(); j++)
		{
			for (int i = 0; i < dimension(); i++) {
				playBoard[i][j].toJSON(writer);
				if(j != dimension()-1 || i != dimension()-1)
				{
					writer.printf(",");
				}
			}
		}
		writer.printf("]");
		writer.printf("}");
    }

    public static class TileAt {
		public final BoardPos pos;
		public final BoardTile tile;
		
		public TileAt(BoardPos pos, BoardTile tile) {
			this.pos = pos;
			this.tile = tile;
		}
	}
}

