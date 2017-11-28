package View;
import Controller.Controller;

/**
 * Created by Andrei on 09.11.2017.
 */
public class RunExample extends Command {
    private Controller ctr;
    public RunExample(String key, String desc,Controller ctr){
        super(key, desc);
        this.ctr=ctr;
    }
    @Override
    public void execute() {
        ctr.allSteps(); }
    }
