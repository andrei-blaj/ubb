using ToyLanguage.Models.States;

namespace ToyLanguage.Models.Interfaces
{
    public interface IExpression
    {
        int Eval(ProgramState state);
    }
}