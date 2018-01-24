package Interpreter.Models.Statements;

import Interpreter.Models.IStatement;
import Interpreter.Models.ProgramState.ProgramState;

public class PassStatement implements IStatement {
    @Override
    public ProgramState execute(ProgramState state) throws Exception {
        return null;
    }

    @Override
    public String toString() {
        return "";
    }
}
