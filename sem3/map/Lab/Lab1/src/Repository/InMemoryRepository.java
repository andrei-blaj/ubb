package Repository;

import Model.GeometricShape;

public class InMemoryRepository implements Repository {
    public int size;
    public GeometricShape[] list;

    public InMemoryRepository(int capacity) {
        size = 0;
        list = new GeometricShape[capacity]; // Fixed Size
    }

    @Override
    public void add(GeometricShape newShape) {
        list[size++] = newShape;
    }

    @Override
    public void remove(GeometricShape shapeToRemove) {
        for (int i = 0; i < size; i++) {
            if (list[i] == shapeToRemove) {
                list[i] = list[size - 1];
                size--;
                i--;
            }
        }
    }

    @Override
    public int getSize() {
        return this.size;
    }

    @Override
    public GeometricShape getIth(int i) {
        return this.list[i];
    }

}
