package Repository;

import Model.GeometricShape;

public interface IRepository {
    void add(GeometricShape newShape) throws CustomException;
    void remove(GeometricShape shapeToRemove) throws CustomException;

    GeometricShape[] filterByVolume(double threshold);

    int getSize();
}
