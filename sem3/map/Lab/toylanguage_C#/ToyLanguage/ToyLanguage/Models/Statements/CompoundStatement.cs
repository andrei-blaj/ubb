using ToyLanguage.Models.Interfaces;
using ToyLanguage.Models.States;

namespace ToyLanguage.Models.Statements
{
    public class CompoundStatement : IStatement
    {
        private readonly IStatement _firstStatement;
        private readonly IStatement _secondStatement;

        public CompoundStatement(IStatement firstStatement, IStatement secondStatement)
        {
            _firstStatement = firstStatement;
            _secondStatement = secondStatement;
        }
        
        public ProgramState Execute(ProgramState state)
        {
            state.ExecutionStack.Push(_secondStatement);
            state.ExecutionStack.Push(_firstStatement);

            return state;
        }

        public override string ToString()
        {
            return $"{_firstStatement}\n{_secondStatement}";
        }
    }
}