/* package models; */
using System;
using System.Collections;
using System.Collections.Generic;

namespace ToyLanguageInterpreter {
    public abstract class Exp {
        abstract public int eval(Dictionary <String, int> symTable);
        /* @Override */
        abstract public String toString();
    }
}
