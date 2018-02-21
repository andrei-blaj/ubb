/* package models; */
/* import java.io.*; */
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;

namespace ToyLanguageInterpreter {
    public class OpenRFileStmt : IStmt {
        private String variable; // name of variable
        private String filename;

        public OpenRFileStmt(String variable, String filename) {
            this.variable = variable;
            this.filename = filename;
        }

        /* @Override */
        public PrgState execute(PrgState state) {
            Dictionary <int, MyFile> fileTable = state.getFileTable();
            Dictionary <String, int> symTable = state.getSymTable();

            foreach(MyFile entry in fileTable.Values) {
                if(entry.getFilename() == this.filename) {
                    Console.WriteLine("File is already open");
                    Environment.Exit(1);
                }
            }

            try {
                StreamReader reader = new StreamReader(this.filename);
                // Assign the first unused file descriptor to this file.
                for(int fd=3; ; fd++)
                    if(!fileTable.ContainsKey(fd)) {
                        fileTable[fd] = new MyFile(this.filename, reader);
                        symTable[variable] = fd;
                        break;
                    }
            } catch(IOException e) {
                Console.Write("Could not open %s for reading.\n", this.filename);
                Console.Write(e.ToString());
                Environment.Exit(1);
            }

            return state;
        }

        /* @Override */
        public String toString() {
            return "OpenRFile(" + this.variable + ", \"" + this.filename + "\")";
        }

    }
}
