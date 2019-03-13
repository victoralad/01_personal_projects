#include "singly_LL.cpp"

int main(){

    Singly_LL<int> list;
    list.add_node(4);
    list.add_node(5);
    list.add_node(6);
    list.add_node(7);
    // list.delete_node();
    // list.add_node(6);
    // list.insert_node_at(2, 7);
    // list.is_empty();
    // list.print_list();
    // list.delete_node_at(1);
    // list.print_list();
    // list.delete_node();
    // list.size_of_list();
    // list.print_node(3);
    list.print_list();
    //list.recursive_rev_list();
    list.reverse();
    list.print_list();
    return 0;
}