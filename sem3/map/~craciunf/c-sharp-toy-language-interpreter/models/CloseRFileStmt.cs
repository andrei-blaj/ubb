/* package models; */
/* import java.io.*; */
using System;
using System.IO;
using System.Collections.Generic;

namespace ToyLanguageInterpreter {
    public class CloseRFileStmt : IStmt {
        private Exp fd;

        public CloseRFileStmt(Exp fd) {
            this.fd = fd;
        }

        /* @Override */
        public PrgState execute(PrgState state) {
            Dictionary <int, MyFile> fileTable = state.getFileTable();
            Dictionary <String, int> symTable = state.getSymTable();

            int fd = 0;
            try {
                fd = this.fd.eval(symTable);
            } catch(Exception e) {
                Console.Write("Could not evaluate expression: %s\n", this.fd.toString());
                Console.Write(e);
                Environment.Exit(1);
            }

            StreamReader reader = fileTable[fd].getReader();
            if(reader == null) {
                Console.Write("File descriptor %d does not exist.\n", fd);
                Environment.Exit(1);
            }

            try {
                reader.Close();
            } catch(Exception e) {
                Console.Write("Could not close reader. Moving on.", fd);
                Console.Write(e);
            }

            fileTable.Remove(fd);

            return state;
        }

        /* @Override */
        public String toString() {
            return "CloseRFile(" + this.fd.toString() + ")";
        }
    }
}
