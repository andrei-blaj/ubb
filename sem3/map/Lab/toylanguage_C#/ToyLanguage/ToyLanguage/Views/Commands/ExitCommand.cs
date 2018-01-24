using System;
using ToyLanguage.Controller;

namespace ToyLanguage.Views
{
    public class ExitCommand : CommandBase
    {
        public ExitCommand(ToyLanguageController controller, string name = "exit", string description = "Exit program.") : base(controller, name, description)
        {
        }

        public override void Execute()
        {
            Console.WriteLine("Goodbye!");
            Environment.Exit(0);
        }
    }
}