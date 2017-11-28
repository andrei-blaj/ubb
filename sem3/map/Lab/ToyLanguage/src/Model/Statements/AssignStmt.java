package Model.Statements;

import Model.ADT.MyIDictionary;
import Model.Expressions.Expression;
import Model.PrgState;

/**
 * Created by Andrei on 20.10.2017.
 */
public class AssignStmt implements IStatement {
    private String id;
    private Expression exp;

    public AssignStmt(String id, Expression exp) {
        this.id = id;
        this.exp = exp;
    }

    @Override
    public PrgState execute(PrgState state) {

        MyIDictionary<String,Integer> symTbl = state.getSymTable();
        int val;
        val=exp.eval(symTbl,state.getHeap());
        if(symTbl.isDefined(id))
            symTbl.update(id,val);
        else
            symTbl.put(id, val);

        return state;
    }

    @Override
    public String toString() {
        return id.toString() + "=" + exp.toString();
    }
}
