package com.company.Views.Commands;

import com.company.Models.Expression;
import com.company.Views.Command;

public class ExitCommand extends Command {

    public ExitCommand(String name, String description) {
        super(name, description);
    }

    @Override
    public void execute() {
        System.exit(0);
    }
}
