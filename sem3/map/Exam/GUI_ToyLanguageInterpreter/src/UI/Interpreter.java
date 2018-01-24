package UI;

import Interpreter.Controller.Controller;
import UI.Controllers.InterpreterController;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Modality;
import javafx.stage.Stage;

public class Interpreter {

    public void show(Controller cont) throws Exception {
        FXMLLoader loader = new FXMLLoader(getClass().getResource("Views/InterpreterView.fxml"));
        Parent interpreterView = loader.load();
        InterpreterController controller = loader.getController();
        controller.setController(cont);
        Stage stage = new Stage();
        stage.initModality(Modality.APPLICATION_MODAL);
        stage.setTitle("Interpreter");
        stage.setScene(new Scene(interpreterView));
        stage.showAndWait();
    }
}
