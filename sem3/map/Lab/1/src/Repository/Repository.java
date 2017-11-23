package Repository;

import Model.GeometricShape;

public class Repository implements IRepository {

    private int size;
    private GeometricShape[] list;

    public Repository(int capacity) {
        size = 0;
        list = new GeometricShape[capacity];
    }

    public void add(GeometricShape newShape) throws CustomException {
        if (list.length == size) {
            throw new CustomException("List is full!");
        }
        list[size++] = newShape;
    }

    public void remove(GeometricShape shapeToRemove) throws CustomException {
        if (size == 0) {
            throw new CustomException("List is empty!");
        }
        for (int i = 0; i < size; i++)
            if (list[i] == shapeToRemove) {
                list[i] = list[size - 1];
                size--;
                i--;
            }
    }

    public int getSize() {
        return size;
    }

    public GeometricShape[] filterByVolume(double threshold) {

        int len = 0;

        for (int i = 0; i < size; i++)
            if (list[i].getVolume() > threshold)
                len++;

        GeometricShape[] resultingList = new GeometricShape[len];
        len = 0;

        for (int i = 0; i < size; i++)
            if (list[i].getVolume() > threshold)
                resultingList[len++] = list[i];

        return resultingList;
    }

}
