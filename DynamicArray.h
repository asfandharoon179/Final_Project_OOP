#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <iostream>
#include <stdexcept>

template <typename T>
class DynamicArray {
private:
    T* data;
    int sizeValue;

public:
    DynamicArray() : data(nullptr), sizeValue(0) {
    }

    explicit DynamicArray(int size) : sizeValue(size) {
        if (size < 0) {
            throw std::invalid_argument("Size cannot be negative.");
        }
        data = new T[size]();
    }

    DynamicArray(const DynamicArray& other) : sizeValue(other.sizeValue) {
        data = new T[sizeValue]();
        for (int i = 0; i < sizeValue; ++i) {
            data[i] = other.data[i];
        }
    }

    DynamicArray& operator=(const DynamicArray& other) {
        if (this == &other) {
            return *this;
        }

        delete[] data;
        sizeValue = other.sizeValue;
        data = new T[sizeValue]();
        for (int i = 0; i < sizeValue; ++i) {
            data[i] = other.data[i];
        }
        return *this;
    }

    ~DynamicArray() {
        delete[] data;
    }

    int getSize() const {
        return sizeValue;
    }

    T& operator[](int index) {
        if (index < 0 || index >= sizeValue) {
            throw std::out_of_range("Index out of range.");
        }
        return data[index];
    }

    const T& operator[](int index) const {
        if (index < 0 || index >= sizeValue) {
            throw std::out_of_range("Index out of range.");
        }
        return data[index];
    }

    void fill(const T& value) {
        for (int i = 0; i < sizeValue; ++i) {
            data[i] = value;
        }
    }

    void pushBack(const T& value) {
        T* expanded = new T[sizeValue + 1]();
        for (int i = 0; i < sizeValue; ++i) {
            expanded[i] = data[i];
        }
        expanded[sizeValue] = value;
        delete[] data;
        data = expanded;
        ++sizeValue;
    }

    bool empty() const {
        return sizeValue == 0;
    }

    int size() const {
        return sizeValue;
    }

    T* begin() {
        return data;
    }

    T* end() {
        return data + sizeValue;
    }

    const T* begin() const {
        return data;
    }

    const T* end() const {
        return data + sizeValue;
    }
};

#endif
