#include "b_search.cpp"

int main(){
    int a[] = {1, 1, 1, 1, 4, 8, 9, 12};
    //std::cout << sizeof(a) / sizeof(a[0]) << std::endl;
    int size = sizeof(a) / sizeof(a[0]);
    b_search <int> obj(a, size);
    obj.search(1, a);
    return 0;
}