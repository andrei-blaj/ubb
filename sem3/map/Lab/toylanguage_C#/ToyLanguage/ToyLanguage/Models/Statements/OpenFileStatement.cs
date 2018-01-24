using System;
using System.IO;
using ToyLanguage.Models.Interfaces;
using ToyLanguage.Models.States;

namespace ToyLanguage.Models.Statements
{
    public class OpenFileStatement : IStatement
    {
        private readonly string _variableFileID;
        private readonly string _filePath;

        public OpenFileStatement(string variableFileId, string filePath)
        {
            _variableFileID = variableFileId;
            _filePath = filePath;
        }
        
        public ProgramState Execute(ProgramState state)
        {
            StreamReader fileStream;

            try
            {
                fileStream = new StreamReader(_filePath);
            }
            catch (Exception e)
            {
                throw new Exception($"Couldn\'t open file with path: {_filePath}");
            }

            int fileID = fileStream.GetHashCode();
            
            state.FileTable[fileID] = new Tuple<string, StreamReader>(_filePath, fileStream);
            state.SymbolTable[_variableFileID] = fileID;
            
            return state;
        }

        public override string ToString()
        {
            return $"OpenFile({_variableFileID}, {_filePath})";
        }
    }
}