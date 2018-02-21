/* package models; */
using System;
using System.Collections.Generic;

namespace ToyLanguageInterpreter {
    public class CompStmt : IStmt {
        private IStmt fst, snd;

        public CompStmt(IStmt fst, IStmt snd) {
            this.fst = fst;
            this.snd = snd;
        }

        /* @Override */
        public  String toString() {
            return "(" + this.fst.toString() + ";\n" + this.snd.toString() + ")";
        }

        /* @Override */
        public  PrgState execute(PrgState state) {
            Stack <IStmt> stack = state.getExeStack();

            stack.Push(this.snd);
            stack.Push(this.fst);

            return state;
        }
    }
}
