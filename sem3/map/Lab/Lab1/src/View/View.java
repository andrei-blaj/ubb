package View;

import Controller.Controller;
import Model.Cube;
import Model.Cylinder;
import Model.Sphere;
import Model.GeometricShape;

public class View {

    public Controller c;

    public View(Controller c) {
        this.c = c;
    }

    public void run() {
        // Outputting the shapes with the volume greater than 25cm3.
        // System.out.println("\n");
        for (GeometricShape shape: this.c.filterByVolume(25.0)) {
            System.out.format("%s\n", shape.toString());
        }
    }

}

