using ToyLanguage.Models.Interfaces;
using ToyLanguage.Models.States;

namespace ToyLanguage.Models.Expressions
{
    public class ConstantExpression : IExpression
    {
        private readonly int _value;

        public ConstantExpression(int value)
        {
            _value = value;
        }

        public int Eval(ProgramState state)
        {
            return _value;
        }

        public override string ToString()
        {
            return _value.ToString();
        }
    }
}