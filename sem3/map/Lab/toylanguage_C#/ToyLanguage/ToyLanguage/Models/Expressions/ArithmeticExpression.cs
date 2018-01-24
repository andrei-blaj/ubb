using System;
using ToyLanguage.Models.Interfaces;
using ToyLanguage.Models.States;

namespace ToyLanguage.Models.Expressions
{
    public class ArithmeticExpression : IExpression
    {
        private readonly IExpression _leftSide;
        private readonly string _operator;
        private readonly IExpression _rightSide;

        public ArithmeticExpression(IExpression leftSide, string op, IExpression rightSide)
        {
            _leftSide = leftSide;
            _operator = op;
            _rightSide = rightSide;
        }
        
        public int Eval(ProgramState state)
        {
            var leftSideValue = _leftSide.Eval(state);
            var rightSideValue = _rightSide.Eval(state);

            if (_operator == "+")
            {
                return leftSideValue + rightSideValue;
            } 
            if (_operator == "-")
            {
                return leftSideValue - rightSideValue;
            }
            if (_operator == "*")
            {
                return leftSideValue * rightSideValue;
            }
            if (_operator == "/")
            {
                if (rightSideValue == 0)
                {
                    throw new Exception("Division by 0!");
                }
                return leftSideValue / rightSideValue;
            }

            return 0;
        }

        public override string ToString()
        {
            return $"{_leftSide} {_operator} {_rightSide}";
        }
    }
}