using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using ToyLanguage.Models.Interfaces;

namespace ToyLanguage.Models.States
{
    public class ProgramState
    {
        private Dictionary<string, int> _symbolTable;
        
        public Dictionary<string, int> SymbolTable
        {
            get { return _symbolTable; }
            set { _symbolTable = value; }
        }

        private Stack<IStatement> _executionStack;

        public Stack<IStatement> ExecutionStack
        {
            get { return _executionStack; }
            set { _executionStack = value; }
        }

        private List<string> _output;

        public List<string> Output
        {
            get { return _output; }
            set { _output = value; }
        }

        private Dictionary<int, Tuple<string, StreamReader>> _fileTable;
        
        public Dictionary<int, Tuple<string, StreamReader>> FileTable
        {
            get { return _fileTable; }
            set { _fileTable = value; }
        }

        public ProgramState()
        {
            _symbolTable = new Dictionary<string, int>();
            _executionStack = new Stack<IStatement>();
            _output = new List<string>();
        }

        public override string ToString()
        {
            var symbolTableStr = new StringBuilder("\n\nSymbol Table:\n");
            var fileTableStr = new StringBuilder("\n\nFile Table:\n");
            var exeStackStr = new StringBuilder("\n\nExe. Stack:\n");
            var outputStr = new StringBuilder("\n\nOutput:\n");
            
            _symbolTable.ToList().ForEach(p => symbolTableStr.Append($"\n{p.Key} = {p.Value.ToString()}"));
            _fileTable.ToList().ForEach(p => fileTableStr.Append($"{p.Key} -> {p.Value.Item1}"));
            _executionStack.ToList().ForEach(p => exeStackStr.Append($"\n{p}"));
            _output.ForEach(p => outputStr.Append($"\n{p}"));
            
            return $"{symbolTableStr}\n{fileTableStr}\n{exeStackStr}\n{outputStr}";
        }
    }
}