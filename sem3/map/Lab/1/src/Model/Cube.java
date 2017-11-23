package Model;

public class Cube implements GeometricShape{

    private double length;

    public Cube(double length) {
        this.length = length;
    }

    public double getVolume() {
        return length * length * length;
    }

    public String toString() {
        return String.format("Cube(%.2f)", this.getVolume());
    }

}
