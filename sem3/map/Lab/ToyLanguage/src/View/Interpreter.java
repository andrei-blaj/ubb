package View;

import Controller.Controller;
import Model.ADT.*;
import Model.Expressions.*;
import Model.Pair;
import Model.PrgState;
import Model.Statements.*;
import Repository.IRepository;
import Repository.Repository;

import java.io.BufferedReader;

/**
 * Created by Andrei on 26.11.2017.
 */
public class Interpreter {

    public static void main(String[] args) {

        MyIStack<IStatement> stk1 = new MyStack<IStatement>();
        MyIDictionary<String, Integer> symTbl1 = new MyDictionary<String, Integer>();
        MyIList<Integer> out1 = new MyList<Integer>();
        MyIFileTable<Integer,Pair<String,BufferedReader>> fileTable1 = new MyFileTable<Integer,Pair<String,BufferedReader>>();
        MyIHeap<Integer,Integer> heap1 = new MyHeap<Integer,Integer>();

        IStatement ex1 = new CompStmt(
                new AssignStmt("v",
                        new ConstExp(2)),
                new PrintStmt(
                        new VarExp("v")));

        PrgState prg1 = new PrgState(stk1,symTbl1,out1,fileTable1,heap1,ex1);
        IRepository repo1 = new Repository("log1.txt");
        repo1.add(prg1);
        Controller ctr1 = new Controller(repo1);

        MyIStack<IStatement> stk2 = new MyStack<IStatement>();
        MyIDictionary<String, Integer> symTbl2 = new MyDictionary<String, Integer>();
        MyIList<Integer> out2 = new MyList<Integer>();
        MyIFileTable<Integer,Pair<String,BufferedReader>> fileTable2 = new MyFileTable<Integer,Pair<String,BufferedReader>>();
        MyIHeap<Integer,Integer> heap2 = new MyHeap<Integer,Integer>();

        IStatement ex2 = new CompStmt(
                new AssignStmt("a",
                        new ArithmeticExpression('+',
                                new ConstExp(2),
                                new ArithmeticExpression('*',
                                        new ConstExp(3),
                                        new ConstExp(0)))),
                new CompStmt(
                        new AssignStmt("b",
                                new ArithmeticExpression('+',
                                        new VarExp("a"),
                                        new ConstExp(1))),
                        new PrintStmt(
                                new VarExp("b"))));

        PrgState prg2 = new PrgState(stk2,symTbl2,out2,fileTable2,heap2,ex2);
        IRepository repo2 = new Repository("log2.txt");
        repo2.add(prg2);
        Controller ctr2 = new Controller(repo2);

        MyIStack<IStatement> stk3 = new MyStack<IStatement>();
        MyIDictionary<String, Integer> symTbl3 = new MyDictionary<String, Integer>();
        MyIList<Integer> out3 = new MyList<Integer>();
        MyIFileTable<Integer,Pair<String,BufferedReader>> fileTable3 = new MyFileTable<Integer,Pair<String,BufferedReader>>();
        MyIHeap<Integer,Integer> heap3 = new MyHeap<Integer,Integer>();

        IStatement ex3 = new CompStmt(
                new AssignStmt("a",
                        new ArithmeticExpression('-',
                                new ConstExp(2),
                                new ConstExp(2))),
                new CompStmt(
                        new IfStmt(
                                new VarExp("a"),
                                new AssignStmt("v",
                                        new ConstExp(2)),
                                new AssignStmt("v",
                                        new ConstExp(3))),
                        new PrintStmt(
                                new VarExp("v"))));

        PrgState prg3 = new PrgState(stk3,symTbl3,out3,fileTable3,heap3,ex3);
        IRepository repo3 = new Repository( "log3.txt");
        repo3.add(prg3);
        Controller ctr3 = new Controller(repo3);

        MyIStack<IStatement> stk4 = new MyStack<IStatement>();
        MyIDictionary<String, Integer> symTbl4 = new MyDictionary<String, Integer>();
        MyIList<Integer> out4 = new MyList<Integer>();
        MyIFileTable<Integer,Pair<String,BufferedReader>> fileTable4 = new MyFileTable<Integer,Pair<String,BufferedReader>>();
        MyIHeap<Integer,Integer> heap4 = new MyHeap<Integer,Integer>();

        IStatement ex4 = new CompStmt(
                new CompStmt(
                        new CompStmt(
                                new openRFile("var_f","test.in"),
                                new readFile(new VarExp("var_f"), "var_c")),
                        new CompStmt(
                                new PrintStmt(
                                        new VarExp("var_f")),
                                new IfStmt(
                                        new VarExp("var_c"),
                                        new PrintStmt(
                                                new VarExp("var_c")),
                                        new PrintStmt(
                                                new ConstExp(0))))),
                new closeRFile(
                        new VarExp("var_f")));

        PrgState prg4 = new PrgState(stk4,symTbl4,out4,fileTable4,heap4,ex4);
        IRepository repo4 = new Repository( "log4.txt");
        repo4.add(prg4);
        Controller ctr4 = new Controller(repo4);

        MyIStack<IStatement> stk5 = new MyStack<IStatement>();
        MyIDictionary<String, Integer> symTbl5 = new MyDictionary<String, Integer>();
        MyIList<Integer> out5 = new MyList<Integer>();
        MyIFileTable<Integer,Pair<String,BufferedReader>> fileTable5 = new MyFileTable<Integer,Pair<String,BufferedReader>>();
        MyIHeap<Integer,Integer> heap5 = new MyHeap<Integer,Integer>();

        IStatement ex5 = new CompStmt(
                new AssignStmt("v",
                        new ConstExp(10)),
                new CompStmt(
                        new NewStatement("v",
                                new ConstExp(20)),
                        new CompStmt(
                                new NewStatement("a",
                                        new ConstExp(22)),
                                new CompStmt(
                                        new wHStmt("a",
                                                new ConstExp(30)),
                                        new CompStmt(
                                                new PrintStmt(
                                                        new VarExp("a")),
                                                new CompStmt(
                                                        new PrintStmt(
                                                                new rHExp("a")),
                                                        new AssignStmt("a",
                                                                new ConstExp(0))))))));

        PrgState prg5 = new PrgState(stk5,symTbl5,out5,fileTable5,heap5,ex5);
        IRepository repo5 = new Repository( "log5.txt");
        repo5.add(prg5);
        Controller ctr5 = new Controller(repo5);

        MyIStack<IStatement> stk6 = new MyStack<IStatement>();
        MyIDictionary<String, Integer> symTbl6 = new MyDictionary<String, Integer>();
        MyIList<Integer> out6 = new MyList<Integer>();
        MyIFileTable<Integer,Pair<String,BufferedReader>> fileTable6 = new MyFileTable<Integer,Pair<String,BufferedReader>>();
        MyIHeap<Integer,Integer> heap6 = new MyHeap<Integer,Integer>();

        IStatement ex6 = new CompStmt(
                new openRFile("f","test.in"),
                new PrintStmt(
                        new ConstExp(2)));

        PrgState prg6 = new PrgState(stk6,symTbl6,out6,fileTable6,heap6,ex6);
        IRepository repo6 = new Repository( "log6.txt");
        repo6.add(prg6);
        Controller ctr6 = new Controller(repo6);

        MyIStack<IStatement> stk7 = new MyStack<IStatement>();
        MyIDictionary<String, Integer> symTbl7 = new MyDictionary<String, Integer>();
        MyIList<Integer> out7 = new MyList<Integer>();
        MyIFileTable<Integer,Pair<String,BufferedReader>> fileTable7 = new MyFileTable<Integer,Pair<String,BufferedReader>>();
        MyIHeap<Integer,Integer> heap7 = new MyHeap<Integer,Integer>();


        IStatement ex7 = new CompStmt(
                new AssignStmt("v",
                        new ConstExp(6)),
                new CompStmt(
                        new whileStmt(
                                new ArithmeticExpression('-',
                                        new VarExp("v"),
                                        new ConstExp(4)),
                                new CompStmt(
                                        new PrintStmt(
                                                new VarExp("v")),
                                        new AssignStmt("v",
                                                new ArithmeticExpression('-',
                                                        new VarExp("v"),
                                                        new ConstExp(1))))),
                        new PrintStmt(
                                new VarExp("v"))));

        PrgState prg7 = new PrgState(stk7,symTbl7,out7,fileTable7,heap7,ex7);
        IRepository repo7 = new Repository( "log7.txt");
        repo7.add(prg7);
        Controller ctr7 = new Controller(repo7);

        TextMenu menu = new TextMenu();
        menu.addCommand(new ExitCommand("0", "exit"));
        menu.addCommand(new RunExample("1", ex1.toString(), ctr1));
        menu.addCommand(new RunExample("2", ex2.toString(), ctr2));
        menu.addCommand(new RunExample("3", ex3.toString(), ctr3));
        menu.addCommand(new RunExample("4", ex4.toString(), ctr4));
        menu.addCommand(new RunExample("5", ex5.toString(), ctr5));
//        menu.addCommand(new RunExample("6", ex6.toString(), ctr6));
//        menu.addCommand(new RunExample("7", ex7.toString(), ctr7));
        menu.show();

    }
}
