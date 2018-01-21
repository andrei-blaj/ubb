/* package models; */
using System;
using System.Collections;
using System.Collections.Generic;

namespace ToyLanguageInterpreter {
    public class ConstExp : Exp {
        private int val;

        public ConstExp(int val) {
            this.val = val;
        }

        /* @Override */
        public override int eval(Dictionary <String, int> symTable) {
            return this.val;
        }

        /* @Override */
        public override String toString() {
            return this.val.ToString();
        }
    }
}
