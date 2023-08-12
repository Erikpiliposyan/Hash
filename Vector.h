#pragma once
#include <iostream>

template <typename T>
class Vector {
public:
    Vector() : capacity(2), size(0) {
        ptr = new T[capacity];
    }

    ~Vector() {
        delete[] ptr;
    }

    void push_back(const T& value) {
        if (size == capacity) {
            capacity *= 2;
            T* newPtr = new T[capacity];
            for (int i = 0; i < size; i++) {
                newPtr[i] = ptr[i];
            }
            delete[] ptr;
            ptr = newPtr;
        }
        ptr[size++] = value;
    }

    void pop_back() {
        if (size > 0) {
            size--;
        }
    }

    void erase(int index) {
        if (index >= 0 && index < size) {
            for (int i = index; i < size - 1; i++) {
                ptr[i] = ptr[i + 1];
            }
            size--;
        }
    }

    int length() const {
        return size;
    }

    T& operator[](int index) {
        if (index >= 0 && index < size) {
            return ptr[index];
        } else {
            throw std::out_of_range("Index out of range");
        }
    }

    T back() const {
        return ptr[size - 1];
    }

    T front() const {
        return ptr[0];
    }

private:
    T* ptr;
    int capacity;
    int size;
};
