/* package repo; */
/* import models.*; */
/* import java.util.*; */
/* import java.io.*; */
/* import java.nio.file.*; */
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;

namespace ToyLanguageInterpreter {
    public class Repository : IRepository {
        private List <PrgState> states;
        private String logFilePath;

        public void prepareLogFilePath(String logFilePath) {
            if(logFilePath == "") {
                Console.Write("Log file: ");
                logFilePath = Console.ReadLine();
            }
            this.logFilePath = logFilePath;

        }

        public Repository(String logFilePath) {
            prepareLogFilePath(logFilePath);
            this.states = new List <PrgState>();
        }

        public Repository(String logFilePath, PrgState initialState) {
            prepareLogFilePath(logFilePath);
            this.states = new List <PrgState>();
            this.states.Add(initialState);
        }

        public PrgState getCurrentState() {
            // LinkedList implements getLast(), but this is
            // a more general List.
            return states[states.Count-1];
        }

        public void logPrgStateExec() {
            /*
            try {
                // TODO: first file open overwrites file.
                PrintWriter logFile = new PrintWriter(new BufferedWriter(new FileWriter(this.logFilePath, true)));

                logFile.println(this.getCurrentState().toString());
                logFile.close();
            } catch(Exception e) {
                    System.err.println(e);
                    throw e;
            }*/

            PrgState state = getCurrentState();

            using (StreamWriter logFile = new StreamWriter(logFilePath, true)) {
                try {
                    logFile.WriteLine("Execution Stack\n");
                    foreach (IStmt statement in state.getExeStack()) {
                        logFile.WriteLine("  " + statement + "\n");
                    }
                    logFile.WriteLine("\n");

                    logFile.WriteLine("Symbol Table\n");
                    foreach (KeyValuePair<string, int> entry in state.getSymTable()) {
                        logFile.WriteLine("  " + entry.Key + " --> " + entry.Value + "\n");
                    }
                    logFile.WriteLine("\n");

                    logFile.WriteLine("File Table\n");
                    foreach (KeyValuePair<int,MyFile> entry in state.getFileTable()) {
                        logFile.WriteLine("  " + entry.Key + " --> " + entry.Value + "\n");
                    }
                    logFile.WriteLine("\n");

                    logFile.WriteLine("Output\n");
                    foreach (int output in state.getStdout()) {
                        logFile.Write("  %d\n", output);
                    }
                    logFile.WriteLine("-------------------\n");
                }
                catch (Exception) {
                    Console.WriteLine("error: could not write to the given file");
                }
            }
        }
    }
}
