#include "dynamic_array.hpp"
#include "array_list.cpp"

template <typename T> 
Dynamic_Array<T>::Dynamic_Array(T arrayIn[], int capacityIn){
    array = new T[capacityIn*2];
    for(int i=0; i<capacityIn; i++){
        array[i] = arrayIn[i];
    }
    growth_factor = 2;
    shrink_factor = growth_factor;
    list_size = capacityIn;
    capacity = capacityIn * growth_factor;
    density = float(list_size)/capacity;
    found = false;
    std::cout << "------------------------------------" << std::endl;
    std::cout << "Initializing dynamic array...\n" << std::endl;
    std::cout << "List successfully initialized!" << std::endl;
    std::cout << "------------------------------------" << std::endl;
    std::cout <<"\n\n";
    std::cout <<"''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''\n\n";
}

template <typename T> 
Dynamic_Array<T>::~Dynamic_Array(){
    std::cout <<"'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''\n\n\n";
    std::cout << "------------------------------------" << std::endl;
    std::cout << "The list_size of the array at the end of the program is " << list_size << "\n\n";
    std::cout << "List has been deleted" << std::endl;
    std::cout << "------------------------------------" << std::endl;
}

template <typename T> 
void Dynamic_Array<T>::add(T valueIn){
    if(density < 0.75){
        array[list_size] = valueIn;
        list_size++;
    }
    else{
        resize(true);
        add(valueIn);
    }

}
template <typename T> 
void Dynamic_Array<T>::insert_at(T valueIn, int positionIn){

    if((positionIn < 1) || (positionIn > list_size+1)){
        std::cout << "This requested insert position is invalid" << "\n";
        std::cout << "Valid index positions must be greater or equal to 1" << "\n";
        std::cout << "Valid index positions must be less or equal to list_size + 1" << "\n";
        std::cout << "The current size of the list is "<< list_size << "\n\n";
    }
    else{
        if(density < 0.75){    
            for(int i = list_size; i > positionIn - 1; i--){
                array[i] = array[i-1];
            }
            array[positionIn - 1] = valueIn;
            list_size++;
        }
        else{
            resize(true);
            insert_at(valueIn, positionIn);
        }
    } 

}


template <typename T> 
void Dynamic_Array<T>::pop(){
    if(density > 0.25){
        array[list_size - 1] = array[list_size];    
        list_size--;
    }
    else{
        resize(false);
        pop();
    }
    
}
template <typename T> 
void Dynamic_Array<T>::pop_at(int positionIn){
    if((positionIn < 1) || (positionIn > list_size)){
        std::cout << "This requested remove position is invalid" << "\n";
        std::cout << "Valid index positions must be greater or equal to 1" << "\n";
        std::cout << "Valid index positions must be less or equal to list_size" << "\n";
        std::cout << "The current size of the list is "<< list_size << "\n\n";
    }
    else{
        if(density > 0.25){
            for(int i = positionIn - 1; i < list_size; i++){
                array[i] = array[i+1];
            }
            list_size--;
        }
        else{
            resize(false);
            pop_at(positionIn);
        }
    }
    
    
}
template <typename T> 
int Dynamic_Array<T>::find(T valueIn){
    for(int i = 0; i < capacity; i++){
        if(array[i] == valueIn){
            std::cout << valueIn << " found at position "<< i + 1 << "\n\n";
            found = true;
            return i + 1;
            break;
        }
    }
    if(found == false){
        std::cout << valueIn << " is not in the array\n\n";
        return 0;
    } 
}

template <typename T> 
T Dynamic_Array<T>::value_at(int positionIn){
    if(positionIn < 1 || positionIn > list_size){
        std::cout << "The requested position is invalid\n";
        std::cout << "The requested position must be greater than zero...\n";
        std::cout << "and less or equal to the capacity of the array\n";
        std::cout << "The current capacity of the array is "<< capacity << "\n\n";
    }
    else{
        std::cout << "Value at position "<< positionIn << " is " << array[positionIn - 1] << "\n\n";
        return array[positionIn - 1];
    }
}

template <typename T> 
int Dynamic_Array<T>::get_sizeof_list(){
    std::cout << "The list_size of the array is " << list_size << "\n\n";
    return list_size;
}

template <typename T> 
void Dynamic_Array<T>::print_array(){
    for(int i = 0; i < list_size; i++){
        std::cout << array[i] << "\n";
    }
    std::cout << "\n";
}

template <typename T> 
void Dynamic_Array<T>::resize(bool increase){
    T* array_new;
    if(increase){
        capacity = capacity * growth_factor;
        density = list_size/capacity;
        array_new = new T[capacity];
        for(int i = 0; i < capacity/growth_factor; i++){
            array_new[i] = array[i];
        }
    }
    else{
        capacity = capacity / shrink_factor;
        density = list_size/capacity;
        array_new = new T[capacity];
        for(int i = 0; i < capacity * shrink_factor; i++){
            array_new[i] = array[i];
        }
    }
    array = array_new;
}