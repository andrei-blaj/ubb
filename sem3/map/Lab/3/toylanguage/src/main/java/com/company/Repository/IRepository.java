package com.company.Repository;

import com.company.Utils.MyIList;
import com.company.Models.ProgramState.ProgramState;

public interface IRepository {
    MyIList<ProgramState> getData();
    void add(ProgramState element);
    void remove(ProgramState element);
    void logProgramState() throws Exception;
}