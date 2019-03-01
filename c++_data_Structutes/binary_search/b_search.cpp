#include <iostream>
template <class T> 
class b_search{
    int size;
    bool found;
    int mid, left, right;
    T* array;
    //T leftArray[], rightArray[];
public:
    b_search(T arrayIn[], int sizeIn);
    ~b_search();
    int search(T number, T arr[]);
    
    
};

template <typename T> 
b_search<T>::b_search(T arrayIn[], int sizeIn){
    std::cout << "Constructor initiated\n";
    array = arrayIn;
    size = sizeIn;
    left = 0;
    right = size;
}

template <typename T> 
b_search<T>::~b_search(){
    std::cout << "Destructor called, program ended\n";
}


// template <typename T> 
// int b_search<T>::search(T number, T arr[]){

//     if(left < right){
//         mid = left + (right - left)/2;
//         std::cout << left << " " << right << " " << mid << "\n";
//         if(array[mid] > number){
//             T leftArray[mid+1];
//             right = mid;
//             for(int i = left; i < mid + 1; i++){
//                 leftArray[i] = array[i];
//             }
//             search(number, leftArray);
//         }

//         else if(array[mid] < number){
//             T rightArray[right + 1];
//             left = mid + 1;
//             for(int i = mid + 1; i < right + 1; i++){
//                 rightArray[i] = array[i];
//             }
//             search(number, rightArray);
//         }

//         else{
//             found = true;
//             std::cout << "The number can be found in the list\n";
//         }
//     }
    
//     else{
//         found = false;
//         std::cout << "The number is not in the list\n";
//     }
// }


template <typename T> 
int b_search<T>::search(T number, T arr[]){

    if(left < right){
        mid = left + (right - left)/2;
        std::cout << left << " " << right << " " << mid << "\n";
        if(array[mid] > number){
            T leftArray[mid];
            right = mid;
            for(int i = left; i < mid; i++){
                leftArray[i] = array[i];
            }
            search(number, leftArray);
        }

        else if(array[mid] < number){
            T rightArray[right];
            left = mid + 1;
            for(int i = mid; i < right; i++){
                rightArray[i] = array[i];
            }
            search(number, rightArray);
        }

        else{
            found = true;
            std::cout << "The number can be found at position: " << mid + 1 << "\n";
        }
    }
    
    else{
        found = false;
        std::cout << "The number is not in the list\n";
    }
}
//RRTs, A*

