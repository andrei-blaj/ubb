/* package models; */
using System;
using System.Collections.Generic;

namespace ToyLanguageInterpreter {
    public class IfStmt : IStmt {
        private Exp exp;
        private IStmt thenStmt, elseStmt;

        public IfStmt(Exp exp, IStmt thenStmt, IStmt elseStmt) {
            this.exp = exp;
            this.thenStmt = thenStmt;
            this.elseStmt = elseStmt;
        }

        /* @Override */
        public String toString() {
            return "if(" + this.exp.toString() + ") then(" + this.thenStmt.toString() + ") else(" + this.elseStmt.toString() + ")";
        }

        /* @Override */
        public PrgState execute(PrgState state) {
            Stack <IStmt> exeStack = state.getExeStack();
            Dictionary <String, int> symTable = state.getSymTable();

            if(this.exp.eval(symTable) != 0)
                exeStack.Push(thenStmt);
            else
                exeStack.Push(elseStmt);

            return state;
        }
    }
}
