package com.company.Models;

import com.company.Models.ProgramState.ProgramState;

public interface IStatement {
    ProgramState execute(ProgramState state) throws Exception;

    String toString();
}
