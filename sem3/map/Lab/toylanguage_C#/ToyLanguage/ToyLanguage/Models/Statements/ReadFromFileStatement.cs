using System;
using System.IO;
using ToyLanguage.Models.Interfaces;
using ToyLanguage.Models.States;

namespace ToyLanguage.Models.Statements
{
    public class ReadFromFileStatement : IStatement
    {
        private readonly string _variableName;
        private readonly IExpression _expressionFileID;

        public ReadFromFileStatement(string variableName, IExpression expressionFileId)
        {
            _variableName = variableName;
            _expressionFileID = expressionFileId;
        }
        
        public ProgramState Execute(ProgramState state)
        {
            int fileID = _expressionFileID.Eval(state);
            
            string line;

            try
            {
                StreamReader fileStream = state.FileTable[fileID].Item2;
                line = fileStream.ReadLine();
            }
            catch (Exception e)
            {
                throw new Exception($"Can\'t read from file with ID = {fileID}");
            }
            
            int value = 0;
            if (!String.IsNullOrWhiteSpace(line))
                int.TryParse(line, out value);

            state.SymbolTable[_variableName] = value;
            
            return state;
        }

        public override string ToString()
        {
            return $"ReadFile({_expressionFileID}, {_variableName})";
        }
    }
    
}