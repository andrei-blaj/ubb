package UI;

import Interpreter.Controller.Controller;
import Interpreter.Models.Expressions.*;
import Interpreter.Models.IStatement;
import Interpreter.Models.ProgramState.ProgramState;
import Interpreter.Models.Statements.*;
import Interpreter.Models.Tables.FileTable;
import Interpreter.Models.Tables.HeapTable;
import Interpreter.Models.Tables.SymTable;
import Interpreter.Repository.Repository;
import Interpreter.Utils.*;
import UI.Controllers.StartUpController;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.io.BufferedReader;
import java.util.ArrayList;
import java.util.List;

public class Main extends Application {

    @Override
    public void start(Stage primaryStage) throws Exception {
        FXMLLoader loader = new FXMLLoader(getClass().getResource("Views/StartUpView.fxml"));
        Parent root = loader.load();
        primaryStage.setTitle("Toy Language Interpreter");

        StartUpController controller = loader.getController();
        controller.setProgramsList(getExamples());

        primaryStage.setScene(new Scene(root));
        primaryStage.show();
    }

    public List<Controller> getExamples() {
        List<Controller> examples = new ArrayList<>();

        examples.add(setUpExample(example1(), "Test 1"));
//        examples.add(setUpExample(example2(), "Test 2"));
//        examples.add(setUpExample(example3(), "Test 3"));

        return examples;
    }

    public Controller setUpExample(List<ProgramState> statements, String exName) {
        Repository repo = new Repository(statements, "/Users/blaj/Downloads/UBB_Bachelor-s_Degree-master/advanced_programming_methods/GUI_ToyLanguageInterpreter/src/Interpreter/logs.data");
        return new Controller(repo, exName);
    }

    public List<ProgramState> example1() {
        List<ProgramState> programs = new ArrayList<>();

        MyIDictionary<String, Integer> symTable = new SymTable();
        MyIDictionary<Integer, Pair<String, BufferedReader>> fileTable = new FileTable();
        HeapTable heapTable = new HeapTable();
        MyIStack<IStatement> stack = new MyStack<>();
        MyList<Integer> output = new MyList<>();
        MyIDictionary<Integer, Integer> latchTable = new MyDictionary<>();

        IStatement firstStatement =
                new AssignmentStatement("v",
                        new ConstantExpression(0)
                );

        IStatement secondStatement = new RepeatStatement(
                new CompoundStatement(
                        new ForkStatement(
                            new CompoundStatement(
                                new PrintStatement(new VariableExpression("v")),
                                new AssignmentStatement(
                                        "v",
                                        new ArithmeticExpression(
                                                new VariableExpression("v"),
                                                "-",
                                                new ConstantExpression(1)
                                        )
                                )
                        )),
                        new AssignmentStatement("v",
                                new ArithmeticExpression(
                                        new VariableExpression("v"),
                                        "+",
                                        new ConstantExpression(1)
                                )
                        )
                ), new BooleanExpression(
                        new VariableExpression("v"),"==", new ConstantExpression(3)));

        IStatement thirdStatement =
                new AssignmentStatement("x",
                        new ConstantExpression(1)
                );

        IStatement fourthStatement =
                new AssignmentStatement("y",
                        new ConstantExpression(2)
                );

        IStatement fifthStatement =
                new AssignmentStatement("z",
                        new ConstantExpression(3)
                );

        IStatement sixthStatement =
                new AssignmentStatement("w",
                        new ConstantExpression(4)
                );

//        IStatement secondStatementt =
//                new ForkStatement(
//                        new CompoundStatement(
//                                new AssignmentStatement(
//                                        "x",
//                                        new ArithmeticExpression(
//                                                new VariableExpression("x"),
//                                                "+",
//                                                new ConstantExpression(10)
//                                        )
//                                ),
//                                new PrintStatement(new VariableExpression("x")),
//
//                        )
//                );

//        IStatement thirdStatement = new AssignmentStatement(
//                "x",
//                new ArithmeticExpression(
//                        new VariableExpression("x"),
//                        "-",
//                        new ConstantExpression(10)
//                )
//        );

        IStatement seventhStatement = new PrintStatement(new ArithmeticExpression(
                new VariableExpression("v"),
                "*",
                new ConstantExpression(10)
        ));

        stack.push(seventhStatement);
        stack.push(sixthStatement);
        stack.push(fifthStatement);
        stack.push(fourthStatement);
        stack.push(thirdStatement);
        stack.push(secondStatement);
        stack.push(firstStatement);

        ProgramState program = new ProgramState(symTable, fileTable, heapTable, stack, output, latchTable);

        programs.add(program);

        return programs;
    }

    public List<ProgramState> example2() {
        List<ProgramState> programs = new ArrayList<>();

        MyIDictionary<String, Integer> symTable = new SymTable();
        MyIDictionary<Integer, Pair<String, BufferedReader>> fileTable = new FileTable();
        HeapTable heapTable = new HeapTable();
        MyIStack<IStatement> stack = new MyStack<>();
        MyList<Integer> output = new MyList<>();
        MyIDictionary<Integer, Integer> latchTable = new MyDictionary<>();

        IStatement firstStatement = new AddInHeapStatement(
                "x",
                new ArithmeticExpression(
                        new ConstantExpression(2),
                        "*",
                        new ConstantExpression(5)
                )
        );

        IStatement secondStatement = new WriteInHeapStatement(
                "x",
                new ArithmeticExpression(
                        new ReadFromHeapExpression("x"),
                        "-",
                        new ConstantExpression(2)
                )
        );

        IStatement thirdStatement = new WriteInHeapStatement(
                "x",
                new ArithmeticExpression(
                        new ReadFromHeapExpression("x"),
                        "-",
                        new ConstantExpression(2)
                )
        );

        IStatement fourthStatement = new AssignmentStatement(
                "x",
                new ConstantExpression(2)
        );

        IStatement fifthStatement = new PrintStatement(new VariableExpression("x"));

        stack.push(fifthStatement);
        stack.push(fourthStatement);
        stack.push(thirdStatement);
        stack.push(secondStatement);
        stack.push(firstStatement);

        ProgramState program = new ProgramState(symTable, fileTable, heapTable, stack, output, latchTable);

        programs.add(program);

        return programs;
    }

    public List<ProgramState> example3() {
        List<ProgramState> programs = new ArrayList<>();

        MyIDictionary<String, Integer> symTable = new SymTable();
        MyIDictionary<Integer, Pair<String, BufferedReader>> fileTable = new FileTable();
        HeapTable heapTable = new HeapTable();
        MyIStack<IStatement> stack = new MyStack<>();
        MyList<Integer> output = new MyList<>();
        MyIDictionary<Integer, Integer> latchTable = new MyDictionary<>();

        IStatement firstStatement =
                new AssignmentStatement("x",
                    new ConstantExpression(10)
                );

        IStatement secondStatement =
                new AssignmentStatement(
                        "x",
                        new ConstantExpression(15)
                );

        IStatement thirdStatement = new AssignmentStatement(
                "x",
                new ArithmeticExpression(
                        new VariableExpression("x"),
                        "-",
                        new ConstantExpression(10)
                )
        );

        IStatement fourthStatement = new PrintStatement(new VariableExpression("x"));

        stack.push(fourthStatement);
        stack.push(thirdStatement);
        stack.push(secondStatement);
        stack.push(firstStatement);

        ProgramState program = new ProgramState(symTable, fileTable, heapTable, stack, output, latchTable);

        programs.add(program);

        return programs;
    }

    public static void main(String[] args) {
        launch(args);
    }
}
