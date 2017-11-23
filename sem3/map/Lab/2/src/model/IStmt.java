package model;

public interface IStmt {
    @Override
    String toString();
    PrgState execute(PrgState state);
}
