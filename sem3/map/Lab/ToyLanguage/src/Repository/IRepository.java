package Repository;

import Exceptions.MyExceptions;
import Model.PrgState;

/**
 * Created by Andrei on 21.10.2017.
 */
public interface IRepository {
    PrgState getCrtPrg();
    void add(PrgState state);
    void logPrgStateExec() throws MyExceptions;
}
