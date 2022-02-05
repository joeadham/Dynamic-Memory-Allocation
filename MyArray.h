#ifndef MyArray_H
#define MyArray_H
#define INITIAL_CAPACITY 8
using namespace std;

template <class T>
class MyArray{
    private:

        int size = 0;
        int capacity = INITIAL_CAPACITY;
        T* data = nullptr;
        
    public:
        MyArray();
        MyArray(T ar[], int size);
        T get(int index);
        void push(T element);
        T pop();
        void insert(int index, T element);
        T remove(int index);
        void print();
        int get_size();
        int get_capacity();
};



#include "MyArray.cpp"
#endif