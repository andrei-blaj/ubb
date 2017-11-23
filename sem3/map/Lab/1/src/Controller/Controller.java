package Controller;

import Model.GeometricShape;
import Repository.CustomException;
import Repository.IRepository;
import Repository.CustomException;

public class Controller {

    IRepository repo;

    public Controller(IRepository repo) {
        this.repo = repo;
    }

    public void add(GeometricShape newShape) throws CustomException {
        this.repo.add(newShape);
    }

    public void remove(GeometricShape shapeToRemove) throws CustomException {
        this.repo.remove(shapeToRemove);
    }

    public GeometricShape[] filterByVolume(double threshold) {
        return this.repo.filterByVolume(threshold);
    }

}
