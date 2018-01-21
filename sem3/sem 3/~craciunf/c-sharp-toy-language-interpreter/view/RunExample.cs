/* package view; */
/* import ctrl.*; */
using System.IO;
using System;

namespace ToyLanguageInterpreter {
    public class RunExample : Command {
        private Controller ctrl;

        public RunExample(String key, String description, Controller ctrl):base(key, description) {}

        /* @Override */
        public override void execute() {

            Console.WriteLine("pula");

            try {
                ctrl.allStep();
            } catch(Exception e) {
                Console.WriteLine("Errors occurred when running the program.");
                Console.WriteLine(e.StackTrace);
                Environment.Exit(1);
            }
        }
    }
}
