#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

template <class T> 
class Dynamic_Array{
    int capacity;
    T* array;
    bool found;
    int list_size;
    float density;
    int growth_factor, shrink_factor;
public:
    Dynamic_Array(T array[], int capacityIn);
    ~Dynamic_Array();
    void add(T valueIn); //
    void insert_at(T valueIn, int positionIn); //
    void pop(); //
    void pop_at(int positionIn); //
    int find(T valueIn); //
    T value_at(int positionIn); //
    int get_sizeof_list();
    void print_array(); //
    void resize(bool increase); //
};

#endif