package thedrake;

import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

public class TroopTile implements Tile, JSONSerializable {
    final Troop troop;
    final PlayingSide side;
    final TroopFace face;

    public TroopTile(Troop troop, PlayingSide side, TroopFace face) {
        this.troop = troop;
        this.side = side;
        this.face = face;
    }

    // Vrací barvu, za kterou hraje jednotka na této dlaždici
    public PlayingSide side(){
        return this.side;
    }

    // Vrací stranu, na kterou je jednotka otočena
    public TroopFace face(){
        return this.face;
    }

    // Jednotka, která stojí na této dlaždici
    public Troop troop(){
        return this.troop;
    }

    @Override
    public boolean canStepOn() {
        return false;
    }

    @Override
    public boolean hasTroop() {
        return true;
    }

    @Override
    public List<Move> movesFrom(BoardPos pos, GameState state) {
        List<Move> newList = new ArrayList<Move>();
        for(TroopAction action : troop.actions(face))
        {
            newList.addAll(action.movesFrom(pos,side,state));
        }
        return newList;
    }

    // Vytvoří novou dlaždici, s jednotkou otočenou na opačnou stranu
    // (z rubu na líc nebo z líce na rub)
    public TroopTile flipped()
    {
        if(this.face == TroopFace.AVERS) {
            return new TroopTile(this.troop, this.side, TroopFace.REVERS);
        }
        else
            return new TroopTile(this.troop, this.side, TroopFace.AVERS);
    }

    @Override
    public void toJSON(PrintWriter writer) {
        writer.printf("{");

        writer.printf("\"troop\":");
        troop.toJSON(writer);

        writer.printf(",\"side\":");
        side.toJSON(writer);

        writer.printf(",\"face\":");
        face.toJSON(writer);

        writer.printf("}");
    }
}
