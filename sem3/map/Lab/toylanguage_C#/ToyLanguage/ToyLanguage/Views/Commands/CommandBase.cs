using System.Security;
using ToyLanguage.Controller;

namespace ToyLanguage.Views
{
    public abstract class CommandBase
    {
        protected ToyLanguageController _controller;
        
        public string Name { get; }

        public string Description { get; }
        
        protected CommandBase(ToyLanguageController controller, string name, string description)
        {
            _controller = controller;
            Description = description;
            Name = name;
        }

        public abstract void Execute();

        public override string ToString()
        {
            return $"{Name}: {Description}";
        }
    }
}