package Model;

public class Sphere implements GeometricShape {

    private double radius;

    public Sphere(double radius) {
        this.radius = radius;
    }

    public double getVolume() {
        return 4.00 * 3.00 * Math.PI * radius * radius * radius;
    }

    public String toString() {
        return String.format("Sphere(%.2f)", getVolume());
    }

}
