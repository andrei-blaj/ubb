using System;
using System.IO;
using ToyLanguage.Models.Interfaces;
using ToyLanguage.Models.States;

namespace ToyLanguage.Models.Statements
{
    public class CloseFileStatement : IStatement
    {
        private readonly IExpression _expressionFileID;

        public CloseFileStatement(IExpression expressionFileId)
        {
            _expressionFileID = expressionFileId;
        }


        public ProgramState Execute(ProgramState state)
        {
            int fileID = _expressionFileID.Eval(state);

            StreamReader fileStream = state.FileTable[fileID].Item2;

            try
            {
                fileStream.Close();
            }
            catch (Exception e)
            {
                throw new Exception($"Can\'t close file with ID = {fileID}");
            }

            state.FileTable.Remove(fileID);

            return state;
        }

        public override string ToString()
        {
            return $"CloseFile({_expressionFileID})";
        }
    }
}