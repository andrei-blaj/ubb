/* package models; */
using System;
using System.Collections;
using System.Collections.Generic;

namespace ToyLanguageInterpreter {
    public class VarExp : Exp {
        private String id;

        public VarExp(String id) {
            this.id = id;
        }

        /* @Override */
        public override int eval(Dictionary <String, int> symTable) {
            return symTable[id];
        }

        /* @Override */
        public override String toString() {
            return this.id;
        }
    }
}
