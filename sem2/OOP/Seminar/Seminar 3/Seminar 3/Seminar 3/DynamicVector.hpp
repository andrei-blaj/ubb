//
//  DynamicVector.hpp
//  Seminar 3
//
//  Created by Andrei Blaj on 3/28/17.
//  Copyright © 2017 Andrei Blaj. All rights reserved.
//

#ifndef DynamicVector_hpp
#define DynamicVector_hpp

#include <stdio.h>

template <typename T>
class DynamicVector {
private:
    T* arr;
    int length;
    int capacity;
    void ResizeVector();
public:
    DynamicVector(int capacity = 5);
    DynamicVector(const DynamicVector &dyn);
    ~DynamicVector();
    void AddElement(const T &obj);
    int getSize() const { return this -> length; };
    DynamicVector& operator = (const DynamicVector &dyn);
};

template <typename T>
DynamicVector<T>::DynamicVector(int capacity) {
    this -> capacity = capacity;
    this -> length = 0;
    
    this -> arr = new T[this -> capacity];
}

template <typename T>
DynamicVector<T>::~DynamicVector() {
    delete[] this -> arr;
}

template <typename T>
void DynamicVector<T>::AddElement(const T &obj) {
    if (length == capacity)
        ResizeVector();
    this -> arr[length++] = obj;
}

template <typename T>
void DynamicVector<T>::ResizeVector() {
    this -> capacity = this -> capacity * 2;
    T* aux = new T[this -> capacity];
    for (int i = 0; i < this -> length; i++) {
        aux[i] = this -> arr[i];
    }
    delete[] this -> arr;
    this -> arr = aux;
}

template <typename T>
DynamicVector<T>::DynamicVector(const DynamicVector &dyn) {
    this -> length = dyn.length;
    this -> capacity = dyn.capacity;
    this -> arr = new T[this -> capacity];
    for (int i = 0; i < this -> length; i++) {
        this -> arr[i] = dyn.arr[i];
    }
}

template <typename T>
DynamicVector<T>& DynamicVector<T>::operator = (const DynamicVector&dyn) {
    this -> capacity = dyn.capacity;
    this -> length = dyn.length;
    
    T* aux = new T[this -> capacity];
    
    for (int i = 0; i < this -> length; i++) {
        aux[i] = dyn.arr[i];
    }
    
    delete[] this -> arr;
    this -> arr = aux;

    return *this;
    
}



#endif /* DynamicVector_hpp */
