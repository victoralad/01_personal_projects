#ifndef SINGLY_LIST_H
#define SINGLY_LIST_H

#include "node.hpp"

template <class T> 
class Singly_LL{
    Node<T>* head;
    int size;
public:
    Singly_LL(Node<T>* start = NULL);
    ~Singly_LL();
    void insert_node_at(int position, T dataIn); //
    void add_node(T dataIn);  //
    void delete_node_at(int position = -1);
    void delete_node(); //
    void print_list();  //
    void print_node(int position);
    int size_of_list(); //
    bool is_empty(); //
    void empty();  //

    // non generic functions on list
    void sort_list(bool ascending = true);
};

#endif