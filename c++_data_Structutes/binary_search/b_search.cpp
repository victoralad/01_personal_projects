#include <iostream>
template <class T> 
class b_search{
    int size;
    T* array;
    T leftArray[], rightArray[];
public:
    b_search(T arrayIn[], int sizeIn);
    ~b_search();
    bool search();
    
    
};

template <typename T> 
b_search<T>::b_search(T arrayIn[], int sizeIn){
    std::cout << "Constructor initiated\n";
    array = arrayIn;
    size = sizeIn;
}

template <typename T> 
b_search<T>::~b_search(){
    std::cout << "Destructor called, program ended\n";
}

template <typename T> 
bool b_search<T>::search(){
    std::cout << "hey \n";
}


