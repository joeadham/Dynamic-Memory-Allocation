
#include "MyArray.h"

/**
 * Constructor for creating a vector with capacity = 8.
 *
 */
template<class T>
MyArray<T>::MyArray() {

    data = new T[capacity];
}

/**
 * Constructor for creating a vector that takes two parameters
 * @tparam T template variable(accepts all variable types)
 * @param ar the input array
 * @param size size of the array
 */
template<class T>
MyArray<T>::MyArray(T ar[], int size) {
    data = new T[capacity];

    for (int i = 0; i < size; i++)
        push(ar[i]); // inserting all of the array's elements to the vector

}


/**
 * inserts a new element one index ahead of the last element in the vector
 * @tparam T template variable(accepts all variable types)
 * @param element the element to be inserted
 */
template<class T>
void MyArray<T>::push(T element) {
// checking if the capacity is equal to the size, if
// it is true then we double the capacity
    capacity = (capacity == size) ? capacity * 2 : capacity;
    data[size] = element;
    size++;

}

/**
 * Inserts an element to a chosen index in the vector.
 * @param index the index number of the new element
 * @param element the element to be added
 */
template<class T>
void MyArray<T>::insert(int index, T element) {
    // re-arranging the elements after due to the insertion
    for (int i = size; i > 0; --i) {
        data[i] = data[size - 1];
    }

    data[index] = element;

}

/**
 * Returns the element stored in the chosen index
 * @param index index of the element
 * @return returns the element
 */
template<class T>
T MyArray<T>::get(int index) {
    return data[index];
}

/**
 * Removes an element in the chosen index, and re-organises the vector accordingly
 * @param index The index of the element to be deleted
 * @return Returns the deleted element or -1 if index is out of range
 */
template<class T>
T MyArray<T>::remove(int index) {
    int i = 0;
    int numberOfElement = 0;
    int lastElementIndex = size - 1;
    T removed = data[index];


    // checks if the removed variable is out of range
    if (index > lastElementIndex) {
        removed = -1;
    }

    data[index] = 0;
    //The following 'if' statement checks if the deleted element should cause a shifting in the element's
    //indexes, and organises them accordingly.
    if (index < lastElementIndex) {
        while (i < size) {
            if (data[i] == 0) {
                data[numberOfElement] = data[numberOfElement + 1];
                data[numberOfElement + 1] = 0;
            }

            i++;

            numberOfElement++;
        }
        size--;
    }
        // this is used for reducing the size to 0 in case the last element has been removed
    else if (index == 0 && lastElementIndex == 0) {
        size--;
    }


    // checking if 1/4 of the capacity is equal to the size, if
    // it is true then we half the capacity
    capacity = (capacity / 4 >= size) ? capacity / 2 : capacity;

    return removed;

}

/**
 * Deletes the last element of the vector
 * @return Returns the deleted element or -1 if there are no elements
 */
template<class T>
T MyArray<T>::pop() {
    int lastElementIndex = size - 1;
    T removed = data[lastElementIndex];
    //checks if there are no more elements remaining in the vector
    if (size == 0) {
        removed = -1;
        return removed;
    }

    data[lastElementIndex] = 0;
    size--;

    // checking if 1/4 of the capacity is equal to the size, if
    // it is true then we half the capacity
    capacity = (capacity / 4 >= size) ? capacity / 2 : capacity;
    return removed;
}


/**
 * Prints the elements of the vector
 * separated by a space
 */
template<class T>
void MyArray<T>::print() {
    for (int i = 0; i < size; ++i) {
        cout << data[i] << " ";

    }
}

/**
 * Returns the capacity of the vector
 * @return capacity
 */
template<class T>
int MyArray<T>::get_capacity() {
    return capacity;
}

/**
 * Returns the size of the vector
 * @return size
 */
template<class T>
int MyArray<T>::get_size() {
    return size;
}









