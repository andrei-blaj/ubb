package com.company;

import com.company.Controller.Controller;
import com.company.Models.*;
import com.company.Models.Expressions.*;
import com.company.Models.ProgramState.ProgramState;
import com.company.Models.Statements.*;
import com.company.Models.Tables.FileTable;
import com.company.Models.Tables.SymTable;
import com.company.Utils.*;
import com.company.Repository.Repository;
import com.company.Views.Command;
import com.company.Views.Commands.ExitCommand;
import com.company.Views.Commands.RunProgramCommand;
import com.company.Views.TextMenu;

import java.io.BufferedReader;

public class Main {

    public static void main(String[] args) {

        Repository repository = getRepositoryExample2();

        Controller controller = new Controller(repository);

        TextMenu textMenu = new TextMenu();

        Command runProgramCommand = new RunProgramCommand("run", "Run the program", controller);
        Command exitCommand = new ExitCommand("exit", "Exit");

        textMenu.add(exitCommand);
        textMenu.add(runProgramCommand);

        textMenu.run();
    }

    private static Repository getRepositoryExample1() {
        MyList<ProgramState> programs = new MyList<>();

        MyIDictionary<String, Integer> symTable = new SymTable();
        MyIDictionary<Integer, Pair<String, BufferedReader>> fileTable = new FileTable();
        MyIStack<IStatement> stack = new MyStack<>();
        MyList<Integer> output = new MyList<>();

        IStatement firstStatement =
                new AssignmentStatement("x",
                        new ArithmeticExpression(
                                new ConstantExpression(5),
                                new String("-"),
                                new ConstantExpression(5)
                        )
                );

        IStatement secondStatement = new IfStatement(
                        new VariableExpression("x"),
                        new AssignmentStatement(
                                "x",
                                new ConstantExpression(20)
                        ),
                        new AssignmentStatement(
                                "x",
                                new ArithmeticExpression(
                                        new VariableExpression("x"),
                                        "+",
                                        new ConstantExpression(1)
                                )
                        )
                );

        IStatement thirdStatement = new PrintStatement(
                new VariableExpression("x")
        );

        stack.push(thirdStatement);
        stack.push(secondStatement);
        stack.push(firstStatement);

        ProgramState program = new ProgramState(symTable, fileTable, stack, output);

        programs.add(program);

        return new Repository(programs, "/Users/blaj/UNI/sem3/map/Lab/3/toylanguage/src/main/java/com/company/log.txt");
    }

    private static Repository getRepositoryExample2() {
        MyList<ProgramState> programs = new MyList<>();

        MyIDictionary<String, Integer> symTable = new SymTable();
        MyIDictionary<Integer, Pair<String, BufferedReader>> fileTable = new FileTable();
        MyIStack<IStatement> stack = new MyStack<>();
        MyList<Integer> output = new MyList<>();

        IStatement firstStatement = new OpenFileStatement(
                "file1",
                "/Users/blaj/UNI/sem3/map/Lab/3/toylanguage/src/main/java/com/company/file1.txt"
        );

        IStatement secondStatement = new OpenFileStatement(
                "file2",
                "/Users/blaj/UNI/sem3/map/Lab/3/toylanguage/src/main/java/com/company/file2.txt"
        );

        IStatement thirdStatement = new ReadFileStatement(
                "x",
                new VariableExpression("file1")
        );

        IStatement fourthStatement = new ReadFileStatement(
                "y",
                new VariableExpression("file2")
        );

        IStatement fifthStatement = new AssignmentStatement(
                "z",
                new ArithmeticExpression(
                        new VariableExpression("x"),
                        "+",
                        new VariableExpression("y")
                )
        );

        IStatement sixthStatement = new PrintStatement(
                new VariableExpression("z")
        );

        stack.push(sixthStatement);
        stack.push(fifthStatement);
        stack.push(fourthStatement);
        stack.push(thirdStatement);
        stack.push(secondStatement);
        stack.push(firstStatement);

        ProgramState program = new ProgramState(symTable, fileTable, stack, output);

        programs.add(program);

        return new Repository(programs, "/Users/blaj/UNI/sem3/map/Lab/3/toylanguage/src/main/java/com/company/log.txt");
    }
}
