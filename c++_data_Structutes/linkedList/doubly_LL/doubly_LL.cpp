#include <iostream>
#include "doubly_LL.hpp"




// default constructor 
template <typename T> 
Singly_LL<T>::Singly_LL(Node<T>* start){
    head = start;
    std::cout << "------------------------------------" << std::endl;
    std::cout << "Initializing List...\n" << std::endl;
    size_of_list();
    std::cout << "" << std::endl;
    std::cout << "List successfully initialized!" << std::endl;
    std::cout << "------------------------------------" << std::endl;
    std::cout <<"\n\n";
    std::cout <<"''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''\n\n";
}

//destructor
template <typename T> 
Singly_LL<T>::~Singly_LL(){
    if (head != NULL){
        delete head; 
        head = NULL;
    }
    std::cout <<"\n";
    std::cout <<"'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''\n\n\n";
    std::cout << "------------------------------------" << std::endl;
    std::cout << "List has been deleted" << std::endl;
    std::cout << "------------------------------------" << std::endl;
}

//add node at a particular position
template <typename T>
void Singly_LL<T>::insert_node_at(int position, T dataIn){
    Node<T>* new_Node = new Node<T>;
    new_Node->data = dataIn; 

    
    if(position == 1 && head != NULL){
        std::cout << dataIn << " has been added to the head of the list\n\n";
        new_Node->next = head;
        head = new_Node;
        size++;
    }
    else if(position == 0){
        std::cout << "The requested insert position is invalid\n";
        std::cout << "Valid positions start at index 1\n\n";
    }
    else {
        if((position - size) == 1){
        add_node(dataIn);
        }
        else if ((position - size) > 1){
            std::cout << "The requested insert position is invalid\n";
            std::cout << "The size of the list is "<< size << "\n\n";
        }
        else{
            Node<T>* temp = head; //for transversing the list
            for(int i = 1; i < position - 1; i++){
                temp = temp->next;     
            }
            new_Node->next = temp->next;
            temp->next = new_Node; 
            size++;
            std::cout << dataIn << " added to the list at position " << position << " ...\n\n";
        }
    }
}

//add a node to the end of the list
template <typename T> 
void Singly_LL<T>::add_node(T dataIn){
    Node<T>* new_Node = new Node<T>;
    new_Node->data = dataIn; 
    if(!head){
        head = new_Node;
        size++;
    }
    else{
        Node<T>* temp = head; //for transversing the list
        while(temp->next != NULL){
            temp = temp->next;     
        }
        temp->next = new_Node; 
        new_Node->prev = temp;
        size++;
    }
    std::cout << dataIn << " added to the end of the list...\n\n";
}

//remove a node from the end of the list
template <typename T> 
void Singly_LL<T>::delete_node(){
    
    //std::cout << "size "<< size << std::endl;
    if(!head){
        empty();
    }
    else if(head->next == NULL){
        std:: cout << head->data << " which is the only node, has been removed from the list... \n";
        delete head;
        head = NULL;
        size--;
    }
    else{   
        Node<T>* temp = head;
        Node<T>* previous;
        while(temp->next){
            previous = temp;
            temp = temp->next;
        }
        std:: cout << temp->data <<" which is the tail node, has been removed from the list... \n";
        previous->next = temp->next;
        if(temp->next){
            temp->next->prev = previous;
        }
        delete temp;
        temp =  NULL;
        size--;
    }
     std::cout << "\n";
}
template <typename T> 
void Singly_LL<T>::delete_node_at(int position){
    Node<T>* temp = head;
    Node<T>* previous;
    if(!head){
        empty();
    }
    else{
        if(position == 0){
            std::cout << "The requested delete position is invalid\n";
            std::cout << "Valid positions start at index 1\n\n";
        }
        else if(position == 1){
            if (head->next == NULL){
                delete_node();
            }
            else{
                std:: cout << head->data << " which is the head node, has been removed from the list... \n";
                head = temp->next;
                delete temp;
                temp = NULL;
                size--;
            } 
        }
        else{
            if(position < size){
                for(int i = 1; i < position; i++){
                    previous = temp;
                    temp = temp->next;
                }
                std::cout << temp->data << " has been deleted from the list at position " << position << "\n\n";
                previous->next = temp->next;
                temp->next->prev = previous;
                delete temp;
                temp =  NULL;
                size--;
            }
            else if(position == size){
                delete_node();
            }
            else{
                std::cout << "The requested delete position is invalid\n";
                std::cout << "The size of the list is "<< size << "\n\n";
            }
            std::cout << "\n";
        }
    }
    
}

//prints the data at a ficed position in the list
template <typename T> 
void Singly_LL<T>::print_node(int position){
    //std::cout << "Printing items in list...\n";
    if(!head){
        empty();
    }
    else if(position == 0){
        std::cout << "The requested print position is invalid\n";
        std::cout << "Valid positions start at index 1\n\n";
    }
    else{
        if ((position - size) > 0){
            std::cout << "The requested print position is invalid\n";
            std::cout << "The size of the list is "<< size << "\n\n";
        }
        else{
            Node<T>* temp = head; //for transversing the list
            for(int i = 1; i < position; i++){
                temp = temp->next;     
            }
            std::cout << "The value at position " << position << " is " << temp->data << " ...\n\n";
        }
    }
    
    std::cout <<"\n";
}

//prints the data in each node of the list
template <typename T> 
void Singly_LL<T>::print_list(){
    std::cout << "Printing items in list...\n";
    if(!head){
        empty();
    }
    else{
        Node<T>* temp = head;
        int temp_size = size;
        while(temp_size){
            std::cout << temp->data << std::endl;
            temp = temp->next;   
            temp_size--;   
        }
    }
    std::cout <<"\n";
}
// check how many nodes are in the list
template <typename T> 
int Singly_LL<T>::size_of_list(){
    std::cout << "Checking the size of the list...\n...";
    if(!head){
        empty();
        size = 0;
    }
    else{        
        Node<T>* temp = head;
        int temp_size = 1;
        while(temp->next != NULL){
            temp = temp->next;
            temp_size++;  
        }
        size = temp_size;   
        std::cout << "The size of the list is " << size << "\n\n";
    }
    return size;
}

//checks if the node is empty
template <typename T> 
bool Singly_LL<T>::is_empty(){
    std::cout << "Checking if list is empty...\n...";
    if(!head){
        empty();
        return true;
    }
    else{
        std::cout << "List is NOT empty" << "\n\n";
        return false;
    }
}

// simply prints out the words "List is empty"
template <typename T> 
void Singly_LL<T>::empty(){
    std::cout << "List is empty\n" << std::endl;
}