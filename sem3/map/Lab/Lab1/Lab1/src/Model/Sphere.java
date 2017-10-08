package Model;

/**
 * Created by blaj on 07/10/2017.
 */
public class Sphere implements GeometricShape {

    private double radius;

    public Sphere(double radius) {
        this.radius = radius;
    }

    @Override
    public double getVolume() {
        // 4/3 * PI * R^3
        return 4.00 / 3.00 * Math.PI * this.radius * this.radius * this.radius;
    }

    @Override
    public String toString() {
        return String.format("Sphere(%.2f)", this.getVolume());
    }

}
