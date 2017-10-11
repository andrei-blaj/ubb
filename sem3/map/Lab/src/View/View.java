package View;

import Model.Cube;
import Model.Cylinder;
import Model.Sphere;

import Controller.Controller;
import Repository.Repository;
import Model.GeometricShape;

public class View {

    public static void main(String[] args) {

        Repository repo = new Repository(100);
        Controller ctrl = new Controller(repo);

        Cube shape1 = new Cube(10);
        Cube shape2 = new Cube(15.23);
        Cylinder shape3 = new Cylinder(1.5, 2);
        Cylinder shape4 = new Cylinder(15, 3.14);
        Sphere shape5 = new Sphere(2.5);
        Sphere shape6 = new Sphere(5);

        try {

            ctrl.add(shape1);
            ctrl.add(shape2);
            ctrl.add(shape3);
            ctrl.add(shape4);
            ctrl.add(shape5);
            ctrl.add(shape6);

        } catch (Exception e) {
            System.out.print("error " + e + "\n");
        }

        for (GeometricShape shape: ctrl.filterByVolume(25.0))
            System.out.format("%s\n", shape.toString());

    }

}
