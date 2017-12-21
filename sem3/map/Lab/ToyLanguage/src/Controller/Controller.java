package Controller;

import Exceptions.MyExceptions;
import Model.ADT.MyIStack;
import Model.Expressions.MyExpException;
import Model.PrgState;
import Model.Statements.IStatement;
import Model.Statements.MyStmtException;
import Repository.IRepository;

import java.util.Collection;
import java.util.HashMap;
import java.util.Map;
import java.util.stream.Collectors;

/**
 * Created by Andrei on 21.10.2017.
 */
public class Controller {
    private IRepository repo;
    private boolean flag;


    public boolean isFlag() {
        return flag;
    }

    public void setFlag(boolean flag) {
        this.flag = flag;
    }



    public Controller(IRepository repo) {
        this.repo = repo;
        this.flag =true;
    }

    Map<Integer,Integer> conservativeGarbageCollector(Collection<Integer> symTableValues, Map<Integer,Integer> heap) {
        return heap.entrySet().stream().filter(e -> symTableValues.contains(e.getKey())).collect(Collectors.toMap(Map.Entry::getKey,Map.Entry::getValue));
    }

    public PrgState oneStep(PrgState state) throws MyExceptions{
        MyIStack<IStatement> stack = state.getExeStack();
        if(stack.isEmpty() == true)
            throw new MyExceptions("Stack is empty");
        IStatement stmt = stack.pop();
        return stmt.execute(state);
    }

    public void allSteps(){
        PrgState prg = repo.getCrtPrg();
        try {
            while (true) {
                oneStep(prg);
                prg.getHeap().setHeap(new HashMap<Integer,Integer>(conservativeGarbageCollector(prg.getSymTable().values(),prg.getHeap().getHeap())));
                repo.logPrgStateExec();
            }
        }catch(MyExceptions e){
            System.out.println(e.toString());
        }
        catch(MyStmtException e){
            System.out.println(e.toString());
        }
        catch(MyExpException e){
            System.out.println(e.toString());
        }
        finally {
            prg.getFileTable().getValues().stream().forEach(v -> { try { v.getSecond().close(); } catch(Exception e) {} } );
            System.out.println(prg.toString());
        }
    }

    @Override
    public String toString() {
        return repo.toString();
    }
}
