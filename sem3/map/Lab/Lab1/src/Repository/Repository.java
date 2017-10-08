package Repository;

import Model.GeometricShape;

public interface Repository {
    void add(GeometricShape newShape);
    void remove(GeometricShape shapeToRemove);
    int getSize();
    GeometricShape getIth(int i);
}
