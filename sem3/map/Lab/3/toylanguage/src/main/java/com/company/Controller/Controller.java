package com.company.Controller;

import com.company.Models.ExceptionFactory;
import com.company.Models.IStatement;
import com.company.Utils.MyIStack;
import com.company.Models.ProgramState.ProgramState;
import com.company.Repository.Repository;

public class Controller {
    private Repository repository;

    public Controller(Repository repository) {
        this.repository = repository;
    }


    public ProgramState executeOneInstruction(ProgramState program) throws Exception {
        MyIStack<IStatement> stack = program.getExeStack();

        if (stack.isEmpty()) {
            throw ExceptionFactory.create("stack", "stack is empty!");
        }

        IStatement statement = stack.pop();


        return statement.execute(program);
    }

    public void executeOne() {
        ProgramState program = this.repository.getData().get(0);

        try {
            executeOneInstruction(program);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public void executeAllProgram() {
        ProgramState program = this.repository.getData().get(0);

        while(!program.getExeStack().isEmpty()) {

            try {
                executeOneInstruction(program);
                this.repository.logProgramState();

            } catch (Exception e) {
                e.printStackTrace();
            }
        }

    }

}
