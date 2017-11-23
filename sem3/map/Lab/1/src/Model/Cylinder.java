package Model;

public class Cylinder implements GeometricShape {

    private double radius, height;

    public Cylinder(double radius, double height) {
        this.radius = radius;
        this.height = height;
    }

    public double getVolume() {
        return Math.PI * radius * radius * height;
    }

    public String toString() {
        return String.format("Cylinder(%.2f)", getVolume());
    }

}
