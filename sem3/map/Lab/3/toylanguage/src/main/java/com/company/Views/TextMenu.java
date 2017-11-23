package com.company.Views;

import java.util.HashMap;
import java.util.Scanner;

public class TextMenu {
    private HashMap<String, Command> commands;
    private Scanner scanner;

    public TextMenu() {
        commands = new HashMap<>();
        this.scanner = new Scanner(System.in);
    }

    public void add(Command command) {
        this.commands.put(command.getName(), command);
    }

    private void printMenu() {
        System.out.println("\nWelcome!");
        for(Command command: this.commands.values()) {
            System.out.println(command);
        }
    }

    public void run() {
        while(true) {
            printMenu();
            System.out.println("Your command: ");
            String commandName = this.scanner.nextLine();

            Command command = this.commands.get(commandName);

            if(command != null) {
                command.execute();
            } else {
                System.out.println("Invalid command!");
            }
        }
    }
}
