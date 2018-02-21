/* package models; */
using System;

namespace ToyLanguageInterpreter {
    public interface IStmt {
        PrgState execute(PrgState state);
        String toString();
    }
}
