#ifndef Doubly_LIST_H
#define Doubly_LIST_H

#include "node.hpp"

template <class T> 
class Doubly_LL{
    Node<T>* head;
    int size;
public:
    Doubly_LL(Node<T>* start = NULL);
    ~Doubly_LL();
    void insert_node_at(int position, T dataIn); 
    void add_node(T dataIn);  //
    void delete_node_at(int position = -1);
    void delete_node(); //
    void print_list();  //
    void print_node(int position); //
    int size_of_list(); 
    bool is_empty(); //
    void empty();  //
    void reverse();
    void recursive_rev_list();
    void recursive_rev(Node<T>* temp);

    // non generic functions on list
    void sort_list(bool ascending = true);
};

#endif