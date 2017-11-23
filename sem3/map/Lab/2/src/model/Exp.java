package model;

public abstract class Exp {
    abstract public int eval(MyIDictionary<String, Integer> symTable);
    @Override
    abstract public String toString();
}