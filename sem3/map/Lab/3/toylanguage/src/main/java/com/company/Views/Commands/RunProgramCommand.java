package com.company.Views.Commands;

import com.company.Controller.Controller;
import com.company.Views.Command;

public class RunProgramCommand extends Command {
    private Controller controller;

    public RunProgramCommand(String name, String description, Controller controller) {
        super(name, description);
        this.controller = controller;
    }

    @Override
    public void execute() {
        this.controller.executeAllProgram();
    }
}
