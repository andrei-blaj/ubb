package Model.Statements;

import Exceptions.MyExceptions;
import Model.PrgState;

/**
 * Created by Andrei on 20.10.2017.
 */
public interface IStatement {
    PrgState execute(PrgState state) throws MyExceptions;
}
