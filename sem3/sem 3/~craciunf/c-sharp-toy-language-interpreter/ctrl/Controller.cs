/*package ctrl;
import models.*;
import repo.*;
import java.io.*;
import java.util.*;
import java.util.stream.*;*/
using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.ObjectModel;

namespace ToyLanguageInterpreter {
    public class Controller {
        private IRepository r;

        public Controller() {
            this.r = new Repository("");
        }

        public Controller(IRepository r) {
            this.r = r;
        }

        public PrgState oneStep(PrgState state) {
            Stack <IStmt> exeStack = state.getExeStack();

            // if(exeStack.isEmpty())
                // return null;
                // throws MyStmtExecException;
            IStmt currentStmt = exeStack.Pop();
            return currentStmt.execute(state);
        }

        public void allStep() {
            PrgState state = r.getCurrentState();

            // initial state
            Console.WriteLine(state.toString());
            try {
                this.r.logPrgStateExec();
            } catch(Exception e) {
                Console.Write(e.ToString());
            }

            while(state.getExeStack().Count != 0) {
                oneStep(state);
                Console.WriteLine(state.toString());
                try {
                    this.r.logPrgStateExec();
                } catch(Exception e) {
                    Console.Write(e.ToString());
                }
            }
        }
    }
}
