/* package view; */
using System;

namespace ToyLanguageInterpreter {
    public class ExitCommand : Command {
        public ExitCommand(String key, String description):base(key, description) {}

        /* @Override */
        public override void execute() {
            Environment.Exit(0);
        }
    }
}
