using ToyLanguage.Models.Interfaces;
using ToyLanguage.Models.States;

namespace ToyLanguage.Models.Statements
{
    public class AssignmentStatement : IStatement
    {
        private readonly string _variableName;
        private readonly IExpression _expression;

        public AssignmentStatement(string variableName, IExpression expression)
        {
            _variableName = variableName;
            _expression = expression;
        }
        
        public ProgramState Execute(ProgramState state)
        {
            state.SymbolTable[_variableName] = _expression.Eval(state);
            
            return state;
        }

        public override string ToString()
        {
            return $"{_variableName} = {_expression}";
        }
    }
}