#include "b_search.cpp"

int main(){
    int a[] = {1, 2, 3, 4, 8, 9, 12};
    //std::cout << sizeof(a) << std::endl;
    b_search <int> obj(a, 7);
    obj.search(0, a);
    return 0;
}