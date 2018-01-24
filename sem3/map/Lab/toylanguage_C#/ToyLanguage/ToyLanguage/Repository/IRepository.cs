using System.Collections.Generic;
using ToyLanguage.Models.States;

namespace ToyLanguage.Repository
{
    public interface IRepository
    {
        List<ProgramState> Programs { get; set; }
        void LogProgramState(ProgramState program);
    }
}