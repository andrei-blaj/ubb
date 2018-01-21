/* package models; */
using System;
using System.Collections;
using System.Collections.Generic;

namespace ToyLanguageInterpreter {
    public class ArithExp : Exp {
        private Exp e1, e2;
        private char op;

        public ArithExp(Exp e1, Exp e2, char op) {
            this.e1 = e1;
            this.e2 = e2;
            this.op = op;
        }

        /* @Override */
        public override int eval(Dictionary <String, int> symTable) {
            int partialRes1 = this.e1.eval(symTable);
            int partialRes2 = this.e2.eval(symTable);

            switch(this.op) {
                case '+': return partialRes1 + partialRes2;
                case '-': return partialRes1 - partialRes2;
                case '*': return partialRes1 * partialRes2;
                case '/': return partialRes1 / partialRes2;
            }

            return 0;
        }

        /* @Override */
        public override String toString() {
            return this.e1.toString() + " " + this.op + " " + this.e2.toString();
        }
    }
}
