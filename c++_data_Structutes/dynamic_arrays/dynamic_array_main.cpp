#include "dynamic_array.cpp"

int main(){

    int a[] = {2, 3, 6, 8, 9};
    int size = sizeof(a)/sizeof(a[0]);
    Dynamic_Array<int> arr(a, size);
    arr.value_at(2);
    arr.find(-3);
    arr.add(7);
    arr.get_sizeof_list();
    arr.pop();
    arr.insert_at(5, 7);
    arr.pop_at(2);
    arr.print_array();
    
    return 0;
}