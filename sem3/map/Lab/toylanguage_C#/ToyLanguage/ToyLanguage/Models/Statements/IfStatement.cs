using ToyLanguage.Models.Interfaces;
using ToyLanguage.Models.States;

namespace ToyLanguage.Models.Statements
{
    public class IfStatement : IStatement
    {
        private readonly IStatement _ifStatement;
        private readonly IExpression _expression;
        private readonly IStatement _elseStatement;

        public IfStatement(IStatement ifStatement, IExpression expression, IStatement elseStatement)
        {
            _ifStatement = ifStatement;
            _expression = expression;
            _elseStatement = elseStatement;
        }


        public ProgramState Execute(ProgramState state)
        {
            var expressionValue = _expression.Eval(state);

            if (expressionValue != 0)
            {
                state.ExecutionStack.Push(_ifStatement);
            }
            else
            {
                state.ExecutionStack.Push(_elseStatement);
            }

            return state;
        }

        public override string ToString()
        {
            return $"if ({_expression}) {{\n{_ifStatement}\n}} else {{\n{_elseStatement}\n}}";
        }
    }
}