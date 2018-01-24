package Interpreter.Models.Statements;

import Interpreter.Models.IStatement;
import Interpreter.Models.ProgramState.ProgramState;
import Interpreter.Models.Tables.SymTable;
import Interpreter.Utils.MyIStack;
import Interpreter.Utils.MyStack;

public class ForkStatement implements IStatement {
    IStatement statement;

    public ForkStatement(IStatement statement) {
        this.statement = statement;
    }
    @Override
    public ProgramState execute(ProgramState state) throws Exception {

        MyIStack<IStatement> newStack = new MyStack<>();
        newStack.push(statement);

        return new ProgramState(
                new SymTable((SymTable) state.getSymTable()),
                state.getFileTable(),
                state.getHeapTable(),
                newStack,
                state.getOutput(),
                state.getLatchTable()
        );
    }

    @Override
    public String toString() {
        return "Fork(\n" + statement + "\n)";
    }
}
