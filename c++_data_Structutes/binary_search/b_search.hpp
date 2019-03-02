#ifndef B_SEARCH_H
#define B_SEARCH_H

#include <iostream>
template <class T> 
class b_search{
    int size;
    bool found;
    int mid, left, right;
    T* array;
public:
    b_search(T arrayIn[], int sizeIn);
    ~b_search();
    int search(T number, T arr[]);
    
    
};

#endif