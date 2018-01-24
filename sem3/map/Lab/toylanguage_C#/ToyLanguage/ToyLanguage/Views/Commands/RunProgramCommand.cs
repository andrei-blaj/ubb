using ToyLanguage.Controller;

namespace ToyLanguage.Views
{
    public class RunProgramCommand : CommandBase
    {
        public RunProgramCommand(ToyLanguageController controller, string name = "run", string description = "Run program.") : base(controller, name, description)
        {
        }

        public override void Execute()
        {
            _controller.ExecuteProgram();
        }
    }
}