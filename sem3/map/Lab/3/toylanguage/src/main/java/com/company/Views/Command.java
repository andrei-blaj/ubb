package com.company.Views;

public abstract class Command {
    private String name, description;

    public Command(String name, String description) {
        this.name = name;
        this.description = description;
    }

    public abstract void execute();

    public String getName() {
        return this.name;
    }

    public String getDescription() {
        return this.description;
    }

    @Override
    public String toString() {
        return this.name + ": " + this.description;
    }
}
