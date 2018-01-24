package Interpreter.Models.Statements;
import Interpreter.Models.IStatement;
import Interpreter.Models.ProgramState.ProgramState;
import Interpreter.Utils.MyIStack;

public class SleepStatement implements IStatement {
    private int time;

    public SleepStatement(int time) {
        this.time = time;
    }

    @Override
    public ProgramState execute(ProgramState state) throws Exception {
        MyIStack<IStatement> exeStack = state.getExeStack();

        if (time > 0) {
            exeStack.push(new SleepStatement(time - 1));
        }

        return null;
    }

    @Override
    public String toString() {
        return "Sleep(" + time + ")\n";
    }

}
