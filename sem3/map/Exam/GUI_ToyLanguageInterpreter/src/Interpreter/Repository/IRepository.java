package Interpreter.Repository;

import Interpreter.Models.ProgramState.ProgramState;

import java.util.List;

public interface IRepository {
    List<ProgramState> getData();
    void add(ProgramState element);
    void remove(ProgramState element);
    void logProgramState(ProgramState program) throws Exception;
}