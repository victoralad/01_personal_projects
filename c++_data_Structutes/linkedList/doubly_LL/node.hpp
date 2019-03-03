#ifndef LIST_H
#define LIST_H

template <typename T> 
struct Node{
    T data;
    Node<T>* next = NULL;
    Node<T>* prev = NULL;
};

#endif