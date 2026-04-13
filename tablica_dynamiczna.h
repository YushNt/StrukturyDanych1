#pragma once
#include <iostream>


template <typename T>
class DynamicArray {
private:
    T* data;
    int size;
    int capacity;

    void reallocate() {
        capacity = (capacity == 0) ? 1 : capacity * 2;
        T* new_data = new T[capacity];
        
        for (int i = 0; i < size; i++) {
            new_data[i] = data[i];
        }
        
        delete[] data;
        data = new_data;
    }

public:
    DynamicArray(int n = 4) : size(0), capacity(n) {
        data = new T[capacity]; 
    }

    ~DynamicArray() {
        delete[] data;
    }

    void push_back(const T& value) {
        if (size == capacity) reallocate(); //podwajanie rozmiaru jeśli pełna
        data[size] = value;
        size++;
    }

    void push_front(const T& value) {
        if (size == capacity) reallocate();
        for (int i = size; i > 0; i--) {
            data[i] = data[i - 1]; 
        }
        data[0] = value;
        size++;
    }

    void insert(int index, const T& value) {
        if (index > size) return; 
        if (size == capacity) reallocate();
        for (int i = size; i > index; i--) {
            data[i] = data[i - 1];
        }
        data[index] = value;
        size++;
    }

    void pop_back() {
        if (size > 0) size--;
    }

    void pop_front() {
        if (size == 0) return;
        for (int i = 0; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
        size--;
    }

    void remove(int index) {
        if (index >= size) return;
        for (int i = index; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
        size--;
    }

    int find(const T& value) const {
        for (int i = 0; i < size; i++) {
            if (data[i] == value) return i; 
        }
        return -1;
    }
    

    int getSize() const { return size; }
    int getCapacity() const { return capacity; }
    T& operator[](int index) { return data[index]; } 
};
