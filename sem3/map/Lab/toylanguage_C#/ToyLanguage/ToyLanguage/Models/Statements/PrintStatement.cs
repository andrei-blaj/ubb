using System;
using ToyLanguage.Models.Interfaces;
using ToyLanguage.Models.States;

namespace ToyLanguage.Models.Statements
{
    public class PrintStatement : IStatement
    {
        private readonly IExpression _expression;

        public PrintStatement(IExpression expression)
        {
            _expression = expression;
        }
        
        public ProgramState Execute(ProgramState state)
        {
            var expressionValue = _expression.Eval(state);
            
            state.Output.Add(expressionValue.ToString());
            
            Console.WriteLine(expressionValue);
            
            return state;
        }

        public override string ToString()
        {
            return $"Print ({_expression})";
        }
    }
}