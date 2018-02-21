/* package models; */
/* import java.io.*; */
using System;
using System.IO;
using System.Collections.Generic;

namespace ToyLanguageInterpreter {
    public class ReadFileStmt : IStmt {
        private Exp fd;
        private String target_var;

        public ReadFileStmt(Exp fd, String target_var) {
            this.fd = fd;
            this.target_var = target_var;
        }

        /* @Override */
        public PrgState execute(PrgState state) {
            Dictionary <int, MyFile> fileTable = state.getFileTable();
            Dictionary <String, int> symTable = state.getSymTable();

            int fd = this.fd.eval(symTable);

            if(!fileTable.ContainsKey(fd)) {
                Console.Write("File descriptor %d does not exist.\n", fd);
                Environment.Exit(1);
            }

            StreamReader reader = fileTable[fd].getReader();
            int val;

            try {
                val = Int32.Parse(reader.ReadLine());
            } catch(Exception e) {
                Console.Write(e);
                val = 0;
            }

            symTable[target_var] = val;
            return state;
        }

        /* @Override */
        public String toString() {
            return "ReadFile(" + this.fd.toString() + ", " + this.target_var + ")";
        }

    }
}
