/* package repo; */
/* import models.*; */
/* import java.io.*; */

namespace ToyLanguageInterpreter {
    public interface IRepository {
        PrgState getCurrentState();
        void logPrgStateExec();
    }
}
