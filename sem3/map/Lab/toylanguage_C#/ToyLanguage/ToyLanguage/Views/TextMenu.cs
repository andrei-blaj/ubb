using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Mime;

namespace ToyLanguage.Views
{
    public class TextMenu
    {
        private Dictionary<string, CommandBase> _commands;

        public TextMenu()
        {
            _commands = new Dictionary<string, CommandBase>();
        }

        public void AddCommand(CommandBase command)
        {
            _commands[command.Name] = command;
        }

        private void PrintMenu()
        {
            Console.WriteLine("\nWelcome!");
            _commands.ToList().ForEach(p => Console.WriteLine(p.Value));
        }

        public void Run()
        {
            while (true)
            {
                PrintMenu();
                Console.WriteLine("Your command: ");
                string line = Console.ReadLine();
                Console.ReadKey();

                CommandBase cmd = _commands.ContainsKey(line) ? _commands[line] : null;

                if (cmd != null)
                {
                    cmd.Execute();
                }
                else
                {
                    Console.WriteLine($"Invalid command + {line}!");
                }
            }
        }
        
    }
}