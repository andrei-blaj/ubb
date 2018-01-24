using System;
using ToyLanguage.Models.Interfaces;
using ToyLanguage.Models.States;

namespace ToyLanguage.Models.Expressions
{
    public class VariableExpression : IExpression
    {
        private readonly string _variableName;

        public VariableExpression(string variableName)
        {
            _variableName = variableName;
        }
        
        public int Eval(ProgramState state)
        {
            if (!state.SymbolTable.ContainsKey(_variableName))
            {
                throw new Exception("Invalid variable name!");
            }

            return state.SymbolTable[_variableName];
        }

        public override string ToString()
        {
            return _variableName;
        }
    }
}