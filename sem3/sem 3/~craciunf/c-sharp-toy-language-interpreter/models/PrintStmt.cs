/* package models; */
using System;
using System.Collections;
using System.Collections.Generic;

namespace ToyLanguageInterpreter {
    public class PrintStmt : IStmt {
        private Exp exp;

        public PrintStmt(Exp exp) {
            this.exp = exp;
        }

        /* @Override */
        public String toString() {
            return "print(" + this.exp.toString() + ")";
        }

        /* @Override */
        public PrgState execute(PrgState state) {
            List <int> stdout = state.getStdout();
            Dictionary <String, int> symTable = state.getSymTable();

            stdout.Add(this.exp.eval(symTable));

            return state;
        }
     }
}
