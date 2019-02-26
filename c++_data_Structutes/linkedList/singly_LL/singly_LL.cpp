#include <iostream>
#include "singly_LL.hpp"

class Singly_LL{
    Node* head;
    int size;
public:
    Singly_LL(Node* start = NULL);
    ~Singly_LL();
    void insert_node_at(int position, int dataIn);
    void add_node(double dataIn);
    void delete_node_at(int positionIn = -1);
    void delete_node();
    void print_list();
    void print_node(int position);
    int size_of_list();
    bool is_empty();
    void empty();

    // non generic functions on list
    void sort_list(bool ascending = true);
};

// default constructor 
Singly_LL::Singly_LL(Node* start){
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
Singly_LL::~Singly_LL(){
    delete head; 
    std::cout <<"\n";
    std::cout <<"'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''\n\n\n";
    std::cout << "------------------------------------" << std::endl;
    std::cout << "List has been deleted" << std::endl;
    std::cout << "------------------------------------" << std::endl;
}

//add a node to the end of the list
void Singly_LL::add_node(double dataIn){
    Node* new_Node = new Node();
    new_Node->data = dataIn; 
    if(!head){
        head = new_Node;
        size++;
    }
    else{
        Node* temp = head; //for transversing the list
        while(temp->next != NULL){
            temp = temp->next;     
        }
        temp->next = new_Node; 
        size++;
    }
    std::cout << dataIn << " added to the end of the list...\n\n";
}

//remove a node from the end of the list
void Singly_LL::delete_node(){
    std::cout << "Trying to delete a node...\n";
    Node* temp = head;
    Node* prev;
    //std::cout << "size "<< size << std::endl;
    if(!head){
        empty();
    }
    else if(temp->next == NULL){
        std:: cout << temp->data << " which is the head node, has been removed from the list \n";
        delete temp;
        temp = NULL;
        size--;
    }
    else{   
        int temp_size = size;
        while(temp->next){
            prev = temp;
            temp = temp->next;
            std::cout << "size "<< prev->data << std::endl;
            temp_size--;
        }
        
        delete temp;
        temp =  NULL;
        std:: cout << prev->data <<" which is the tail node, has been removed from the list \n";
        size--;
    }
     std::cout << "\n";
}
void Singly_LL::delete_node_at(int positionIn){
    Node* temp = head;
    Node* prev;
    if(positionIn <= size){
        for(int i = 0; i < positionIn; i++){
            prev = temp;
            temp = temp->next;
        }
        prev = temp->next;
        temp =  NULL;
        delete temp;
        size--;
    }
    else{
        std::cout << "The size of the list is less than the index given...\n";
        size_of_list();
    }
    std::cout << "\n";
    
}

//prints the data in each node of the list
void Singly_LL::print_list(){
    std::cout << "Printing items in list...\n";
    if(!head){
        empty();
    }
    else{
        Node* temp = head;
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
int Singly_LL::size_of_list(){
    std::cout << "Checking the size of the list...\n...";
    if(!head){
        empty();
        size = 0;
    }
    else{        
        Node* temp = head;
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
bool Singly_LL::is_empty(){
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
void Singly_LL::empty(){
    std::cout << "List is empty\n" << std::endl;
}