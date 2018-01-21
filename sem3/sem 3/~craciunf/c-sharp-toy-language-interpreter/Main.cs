using System;

/*using models;
using repo;
using ctrl;
using view;
using view.TextMenu;
using java.util;*/

namespace ToyLanguageInterpreter {
    public class Interpreter {
        public static void Main(String[] args) {
            TextMenu menu = new TextMenu();

            String logFilePath = "main.log";

            menu.addCommand(new RunExample("1", "Lab2ex1", TextMenu.generateController(logFilePath, TextMenu.generateExample1())));
            menu.addCommand(new RunExample("2", "Lab2ex2", TextMenu.generateController(logFilePath, TextMenu.generateExample2())));
            menu.addCommand(new RunExample("3", "Lab2ex2", TextMenu.generateController(logFilePath, TextMenu.generateExample3())));
            menu.addCommand(new RunExample("4", "Lab5ex1", TextMenu.generateController(logFilePath, TextMenu.generateExample4())));
            menu.addCommand(new RunExample("5", "Lab5ex2", TextMenu.generateController(logFilePath, TextMenu.generateExample5())));

            menu.run();
        }
    }
}
