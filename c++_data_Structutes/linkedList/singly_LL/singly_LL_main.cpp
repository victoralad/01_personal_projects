#include "singly_LL.cpp"

int main(){

    Singly_LL list;
    list.add_node(4);
    list.add_node(5);
    list.add_node(6);
    list.is_empty();
    list.delete_node();
    //list.delete_node();
    list.size_of_list();
    list.print_list();
    return 0;
}