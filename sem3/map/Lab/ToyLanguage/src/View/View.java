package View;

/**
 * Created by Andrei on 21.10.2017.
 */
//public class View {
//    public static void main(String[] args){
//
//        MyIStack<IStatement> stk = new MyStack<IStatement>();
//        MyIDictionary<String, Integer> symTbl = new MyDictionary<String,Integer>();
//        MyIList<Integer> out = new MyList<Integer>();
//
//        IStatement ex1=new CompStmt(new AssignStmt("v",new ConstExp(2)), new PrintStmt(new VarExp("v")));
//        IStatement ex2 = new CompStmt(new AssignStmt("a", new ArithmeticExpression('+',new ConstExp(2),new
//                ArithmeticExpression('*',new ConstExp(3), new ConstExp(0)))),
//                new CompStmt(new AssignStmt("b",new ArithmeticExpression('+',new VarExp("a"), new
//                        ConstExp(1))), new PrintStmt(new VarExp("b"))));
//
//        IStatement ex3 = new CompStmt(new AssignStmt("a", new ArithmeticExpression('-',new ConstExp(2), new
//                ConstExp(2))),new CompStmt(new IfStmt(new VarExp("a"),new AssignStmt("v",new ConstExp(2)), new
//                        AssignStmt("v", new ConstExp(3))), new PrintStmt(new VarExp("v"))));
//
//        PrgState prg = new PrgState(stk, symTbl, out, ex2);
//        System.out.println(prg.toString());
//
//        IRepository repo = new Repository("test.txt");
//        repo.add(prg);
//        Controller ctrl = new Controller(repo);
//        ctrl.allSteps();
//
//
//    }
//}
