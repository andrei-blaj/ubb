package Interpreter.Models;

import Interpreter.Models.ProgramState.ProgramState;

public abstract class Expression {

    public abstract int eval(ProgramState state) throws Exception;

    @Override
    public abstract String toString();
}
