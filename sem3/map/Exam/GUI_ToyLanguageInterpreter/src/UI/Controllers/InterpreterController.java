package UI.Controllers;

import Interpreter.Controller.Controller;
import Interpreter.Models.IStatement;
import Interpreter.Models.ProgramState.ProgramState;
import javafx.scene.control.*;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.stage.Stage;

import java.net.URL;
import java.util.Collections;
import java.util.List;
import java.util.ResourceBundle;
import java.util.stream.Collectors;

public class InterpreterController implements Initializable {

    public InterpreterController() {}

    private Integer selectedProgramID;
    private ProgramState selectedProgram;

    @FXML
    public TextField currentSelectedProgram = new TextField("");

    @FXML
    public void setSelectedProgram() {
        if (programs.getSelectionModel().getSelectedItem() != null) {
            selectedProgramID = programs.getSelectionModel().getSelectedItem();
            selectedProgram = controller.getProgramState(selectedProgramID);
            currentSelectedProgram.setText(selectedProgramID.toString());
            loadData();
        }
    }

    private void loadData() {
        programs.getItems().setAll( controller.getPrograms().stream().map(ProgramState::getID).collect(Collectors.toList()) );

        if (selectedProgram != null) {
            List<String> exeStackElems = selectedProgram.getExeStack().getData().stream().map(IStatement::toString).collect(Collectors.toList());
            Collections.reverse(exeStackElems);
            executionStack.getItems().setAll(exeStackElems);
            output.getItems().setAll(selectedProgram.getOutput().getData().stream().map(Object::toString).collect(Collectors.toList()));

            symbolTableNames.getItems().setAll(selectedProgram.getSymTable().getKeys());
            symbolTableValues.getItems().setAll(selectedProgram.getSymTable().getValues().stream().map(Object::toString).collect(Collectors.toList()));

            fileTableNames.getItems().setAll(selectedProgram.getFileTable().getKeys().stream().map(Object::toString).collect(Collectors.toList()));
            fileTablePaths.getItems().setAll(selectedProgram.getFileTable().getValues().stream().map(p -> p.getSecond().toString()).collect(Collectors.toList()));

            heapTableAddresses.getItems().setAll(selectedProgram.getHeapTable().getKeys().stream().map(Object::toString).collect(Collectors.toList()));
            heapTableValues.getItems().setAll(selectedProgram.getHeapTable().getValues().stream().map(Object::toString).collect(Collectors.toList()));
        }
    }

    private Controller controller;

    public void setController(Controller cont) {
        controller = cont;

        selectedProgram = controller.getPrograms().get(0);
        selectedProgramID = selectedProgram.getID();
        currentSelectedProgram.setText(selectedProgramID.toString());

        loadData();
    }

    @FXML
    public Button runButton;

    public void onRunButtonPressed() {
        controller.executeAllProgram();
        loadData();
    }

    @FXML
    public Button runOneStepButton;

    @FXML
    public void onRunOneStepButtonPressed() {
        try {
            controller.executeOneStepProgram();
        } catch (Exception e) {
            Alert alert = new Alert(Alert.AlertType.INFORMATION);
            alert.setTitle("Interpreter");
            alert.setHeaderText("Interpreter info");
            alert.setContentText("The program is over!");
            alert.showAndWait().ifPresent(rs -> {
                if (rs == ButtonType.OK) {
                    System.out.println("Pressed OK.");
                }
            });
        }
        loadData();
    }

    @FXML
    public Button exitButton;

    @FXML
    public void onExitButtonPressed() {
        Stage stage = (Stage) exitButton.getScene().getWindow();
        stage.close();
    }

    @FXML
    public ListView<String> output = new ListView<>();
    @FXML
    public ListView<Integer> programs = new ListView<>();
    @FXML
    public ListView<String> executionStack = new ListView<>();


    @FXML
    public ListView<String> symbolTableNames = new ListView<>();
    @FXML
    public ListView<String> symbolTableValues = new ListView<>();


    @FXML
    public ListView<String> fileTableNames = new ListView<>();
    @FXML
    public ListView<String> fileTablePaths = new ListView<>();

    @FXML
    public ListView<String> heapTableAddresses = new ListView<>();
    @FXML
    public ListView<String> heapTableValues = new ListView<>();

    @Override
    public void initialize(URL location, ResourceBundle resources) {
    }
}
