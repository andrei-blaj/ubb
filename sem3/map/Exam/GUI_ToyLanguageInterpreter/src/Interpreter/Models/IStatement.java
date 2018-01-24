package Interpreter.Models;

import Interpreter.Models.ProgramState.ProgramState;

public interface IStatement {
    ProgramState execute(ProgramState state) throws Exception;

    String toString();
}
