#include <iostream>
#include <unordered_set>
#include "Vector.h"

template <typename T>
void moveElementsToUnorderedSet(Vector<T>& vec, std::unordered_set<T>& unorderedSet) {
    for (int i = 0; i < vec.length(); ++i) {
        unorderedSet.insert(vec[i]);
    }
    vec = Vector<T>();
}

template <typename T>
void printUnorderedSet(const std::unordered_set<T>& unorderedSet) {
    for (auto element : unorderedSet) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

int main() {
    Vector<int> myVector;

    myVector.push_back(10);
    myVector.push_back(20);
    myVector.push_back(30);

    std::cout << "Vector length: " << myVector.length() << std::endl;

    std::cout << "Vector elements: ";
    for (int i = 0; i < myVector.length(); ++i) {
        std::cout << myVector[i] << " ";
    }
    std::cout << std::endl;

    std::unordered_set<int> unorderedSet;
    moveElementsToUnorderedSet(myVector, unorderedSet);

    std::cout << "Elements in unordered_set: ";
    printUnorderedSet(unorderedSet);

    return 0;
}
