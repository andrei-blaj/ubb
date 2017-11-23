package model;

public class ConstExp extends Exp {
    public int value;

    public ConstExp(int value) {
        this.value = value;
    }

    @Override
    public int eval(MyIDictionary<String, Integer> symTable) {
        return value;
    }

    @Override
    public String toString() {
        return String.valueOf(value);
    }
}
