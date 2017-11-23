package repository;

import model.PrgState;
import java.util.ArrayList;
import java.util.List;

public class Repository implements IRepository {

    private PrgState crtPrg;
    private List <PrgState> prgList;

    public Repository(PrgState state) {
        this.prgList = new ArrayList<>();
        this.prgList.add(state);
    }

    @Override
    public List <PrgState> getPrgList() {
        return this.prgList;
    }

    @Override
    public PrgState getCrtPrg() {
        return this.crtPrg;
    }



}
