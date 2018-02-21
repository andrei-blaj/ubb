/* package models; */
using System;
using System.Collections;
using System.Collections.Generic;

namespace ToyLanguageInterpreter {
    public class PrgState {
        private Stack <IStmt> exeStack;
        private Dictionary <String, int> symTable;
        private List <int> stdout;
        private Dictionary <int, MyFile> fileTable;
        private IStmt initialProgram; //optional field, but good to have

        public PrgState(Stack <IStmt> exeStack,
                Dictionary <String, int> symTable,
                List <int> stdout,
                Dictionary <int, MyFile> fileTable,
                IStmt initialProgram) {
            this.exeStack = exeStack;
            this.symTable = symTable;
            this.stdout = stdout;
            this.fileTable = fileTable;
            this.initialProgram = initialProgram;
            this.exeStack.Push(initialProgram);
        }

        public PrgState(IStmt initialProgram) {
            this.exeStack = new Stack <IStmt>();
            this.symTable = new Dictionary <String, int>();
            this.stdout = new List <int>();
            this.fileTable = new Dictionary <int, MyFile>();
            this.initialProgram = initialProgram;
            this.exeStack.Push(initialProgram);
        }

        /* @Override */
        public String toString() {
            return "exeStack:\n" + this.exeStack.ToString() +
                   "symTable:\n" + this.symTable.ToString() +
                   "fileTable:\n" + this.fileTable.ToString() +
                   "stdout:\n" + this.stdout.ToString();

        }

        public Stack <IStmt> getExeStack() {
            return this.exeStack;
        }

        public Dictionary <String, int> getSymTable() {
            return this.symTable;
        }

        public List <int> getStdout() {
            return this.stdout;
        }

        public Dictionary <int, MyFile> getFileTable() {
            return this.fileTable;
        }

        public IStmt getInitialProgram() {
            return this.initialProgram;
        }

        public void setExeStack(Stack <IStmt> exeStack) {
            this.exeStack = exeStack;
        }

        public void setSymTable(Dictionary <String, int> symTable) {
            this.symTable = symTable;
        }

        public void setStdout(List <int> stdout) {
            this.stdout = stdout;
        }

        public void setFileTable(Dictionary <int, MyFile> fileTable) {
            this.fileTable = fileTable;
        }

        public void setInitialProgram(IStmt initialProgram) {
            this.initialProgram = initialProgram;
        }
    }
}
