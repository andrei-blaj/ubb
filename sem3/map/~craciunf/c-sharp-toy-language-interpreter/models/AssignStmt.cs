/* package models; */
using System;
using System.Collections;
using System.Collections.Generic;

namespace ToyLanguageInterpreter {
    public class AssignStmt : IStmt {
        private String id;
        private Exp exp;

        public AssignStmt(String id, Exp exp) {
            this.id = id;
            this.exp = exp;
        }

        /* @Override */
        public String toString() {
            return id + " = " + exp.toString();
        }

        /* @Override */
        public PrgState execute(PrgState state) {
            // MyIStack <IStmt> stack = state.getExeStack();
            Dictionary <String, int> symTable = state.getSymTable();

            int val = this.exp.eval(symTable);
            // if(symTable.containsKey(id))
            //     symTable.put(id, val);
            // else
            symTable.Add(this.id, val);

            return state;
        }
    }
}
