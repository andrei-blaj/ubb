using ToyLanguage.Models.States;

namespace ToyLanguage.Models.Interfaces
{
    public interface IStatement
    {
        ProgramState Execute(ProgramState state);
    }
}