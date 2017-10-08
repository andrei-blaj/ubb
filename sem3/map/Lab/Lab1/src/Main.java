// 7. Se da o colectie de mai multe obiecte
// avind forme de cuburi, sfere si cilindrii.
// Sa se afiseze obiectele avind volumul mai mare
// decit 25cm3.

import Repository.InMemoryRepository;
import Controller.Controller;
import View.View;
import Model.GeometricShape;
import Model.Cube;
import Model.Cylinder;
import Model.Sphere;

public class Main {

    public static void main(String[] args) {

        // Creating a repository, controller and view and 'connecting' them.
        InMemoryRepository r = new InMemoryRepository(100);
        Controller c = new Controller(r);
        View ui = new View(c);

        // Hardcoding a few shapes.
        Cube shape1 = new Cube(10);
        Cube shape2 = new Cube(15.23);
        Cylinder shape3 = new Cylinder(1.5, 2);
        Cylinder shape4 = new Cylinder(15, 3.14);
        Sphere shape5 = new Sphere(2.5);
        Sphere shape6 = new Sphere(5);

        // Adding the shapes to the repository through the controller.
        ui.c.add(shape1);
        ui.c.add(shape2);
        ui.c.add(shape3);
        ui.c.add(shape4);
        ui.c.add(shape5);
        ui.c.add(shape6);

        // Running the problem.
        // Should output the shapes with the volume greater than 25cm3.
        ui.run();

    }

}
