package Controller;

import Model.GeometricShape;
import Repository.Repository;

public class Controller {

    Repository r;

    public Controller(Repository r) {
        this.r = r;
    }

    public void add(GeometricShape newShape) {
        this.r.add(newShape);
    }

    public void remove(GeometricShape shapeToRemove) {
        this.r.remove(shapeToRemove);
    }

    public GeometricShape[] filterByVolume(double threshold) {

        int solutionSize = 0;

        for (int i = 0; i < this.r.getSize(); i++)
            if (this.r.getIth(i).getVolume() > threshold)
                solutionSize++;

        GeometricShape[] result = new GeometricShape[solutionSize];
        int resultSize = 0;

        for (int i = 0; i < this.r.getSize(); i++)
            if (this.r.getIth(i).getVolume() > threshold)
                result[resultSize++] = this.r.getIth(i);

        return result;
    }

}
