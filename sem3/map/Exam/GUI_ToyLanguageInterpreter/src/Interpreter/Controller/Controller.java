package Interpreter.Controller;

import Interpreter.Models.ProgramState.ProgramState;
import Interpreter.Models.Tables.HeapTable;
import Interpreter.Repository.Repository;
import Interpreter.Utils.MyIDictionary;
import Interpreter.Utils.Pair;

import java.io.BufferedReader;
import java.util.*;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.stream.Collectors;

public class Controller {
    private Repository repository;
    private final ExecutorService executor = Executors.newFixedThreadPool(10);
    private final String programName;

    public List<ProgramState> getPrograms() { return repository.getData(); }
    public Controller(Repository repository, String programName) {
        this.repository = repository;
        this.programName = programName;
    }

    public String getProgramName() { return programName; }

    private HashMap<Integer, Integer> garbageCollector(
            Collection<Integer> symTableValues, HashMap<Integer, Integer> heapTable) {

        HashMap<Integer, Integer> newHeapTable = new HashMap<>();

        for(Integer key: heapTable.keySet()) {
            if (symTableValues.contains(key)) {
                newHeapTable.put(key, heapTable.get(key));
            }
        }

        return newHeapTable;
    }

    public void executeOneStepForAllPrograms(List<ProgramState> programs) throws InterruptedException {
        List<Callable<ProgramState>> callList = programs.stream()
                .map((ProgramState p) -> (Callable<ProgramState>)(p::executeOneInstruction))
                .collect(Collectors.toList());

        List<ProgramState> newProgramStates = this.executor.invokeAll(callList).stream()
                .map(future -> {
                    try {
                        return future.get();
                    } catch (Exception e) {
                        return null;
                    }
                }).filter(Objects::nonNull)
                .collect(Collectors.toList());

        programs.addAll(newProgramStates);

        programs.forEach(p -> {
            try {
                this.repository.logProgramState(p);
            } catch (Exception e) {
                e.printStackTrace();
            }
        });
    }

    public Set<Integer> mergeSymTableValues(List<ProgramState> programs) {
        Set<Integer> result = new HashSet<Integer>();

        programs.stream().forEach(p -> result.addAll(p.getSymTable().getMyDictionary().values()));

        return result;
    }

    public void executeAllProgram() {
        List<ProgramState> programs = this.repository.getData();
        HeapTable heapTable = programs.get(0).getHeapTable();
        MyIDictionary<Integer, Pair<String, BufferedReader>> fileTable = programs.get(0).getFileTable();

        while(!programs.isEmpty()) {
            try {
                executeOneStepForAllPrograms(programs);
                programs = programs.stream().filter(p -> p.isNotCompleted()).collect(Collectors.toList());
                this.repository.setData(programs);

                heapTable.setHashMap(
                        garbageCollector(
                                mergeSymTableValues(programs),
                                heapTable.getHashMap()
                        )
                );

            } catch (Exception e) {
                e.printStackTrace();
            } finally {
                fileTable.getMyDictionary().values().stream().forEach(f -> {
                        try {
                            f.getSecond().close();
                        } catch (Exception e) {
                        }
                });
            }

        }
    }

    public ProgramState getProgramState(long ID) {
        return repository.getData().stream().filter(p -> p.getID() == ID).findFirst().get();
    }

    public boolean executeOneStepProgram() {
        List<ProgramState> programs = this.repository.getData();
        HeapTable heapTable = programs.get(0).getHeapTable();
        MyIDictionary<Integer, Pair<String, BufferedReader>> fileTable = programs.get(0).getFileTable();

        if(!programs.isEmpty()) {
            try {
                executeOneStepForAllPrograms(programs);
                programs = programs.stream().filter(p -> p.isNotCompleted()).collect(Collectors.toList());
                this.repository.setData(programs);

                heapTable.setHashMap(
                        garbageCollector(
                                mergeSymTableValues(programs),
                                heapTable.getHashMap()
                        )
                );

            } catch (Exception e) {
                e.printStackTrace();
            } finally {
                fileTable.getMyDictionary().values().stream().forEach(f -> {
                    try {
                        f.getSecond().close();
                    } catch (Exception e) {
                    }
                });
            }
            return true;
        }

        return false;
    }

}
