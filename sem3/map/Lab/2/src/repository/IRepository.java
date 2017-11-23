package repository;

import model.PrgState;
import java.util.List;

public interface IRepository {
    PrgState getCrtPrg();
    List <PrgState> getPrgList();
}