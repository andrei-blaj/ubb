/* package models; */
/* import java.io.*; */
using System;
using System.IO;

namespace ToyLanguageInterpreter {
    public class MyFile {
        private String filename;
        private StreamReader reader;

        public MyFile(String filename, StreamReader reader) {
            this.filename = filename;
            this.reader = reader;
        }

        public String getFilename() {
            return this.filename;
        }

        public StreamReader getReader() {
            return this.reader;
        }

        public void setFilename(String filename) {
            this.filename = filename;
        }

        public void setReader(StreamReader reader) {
            this.reader = reader;
        }

        /* @Override */
        public String toString() {
            return "MyFile(\"" + this.filename + "\", " + this.reader.ToString() + ")";
        }
    }
}
