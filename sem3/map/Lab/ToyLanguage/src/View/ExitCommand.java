package View;

/**
 * Created by Andrei on 09.11.2017.
 */
public class ExitCommand extends Command {
    public ExitCommand(String key, String desc){
        super(key, desc);
    }
    @Override
    public void execute() {
        System.exit(0);
    }

}
