package com.company.Views;

import com.company.Controller.Controller;

import java.util.Scanner;

public class View {
    private Controller controller;
    private Scanner scanner;

    public View(Controller controller) {
        this.controller = controller;
        this.scanner = new Scanner(System.in);
    }

    public void startApp() {

        System.out.print(
                        "Press 0 to exit.\n" +
                        "Press 1 to execute one instruction.\n" +
                        "Press 2 to execute all program.\n" +
                        "Your command: "
        );

        int command = this.scanner.nextInt();

        if (command == 1) {
            try {
                this.controller.executeOne();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }

        if (command == 2) {
            this.controller.executeAllProgram();
        }
    }
}
