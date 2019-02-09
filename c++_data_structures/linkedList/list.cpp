#include<iostream>
#include "list.hpp"

using namespace std; 

List::List(){
    head = NULL;
    curr = NULL;
    temp = NULL;
}

void List::addNode(int addData){
    nodePtr n = new node;
    n->next = NULL;
    n->data = addData;

    if(head != NULL){
        curr = head;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = n;
    }
    else{
        head = n;
    }

}

void List::delNode(int delData){
    nodePtr delPtr = new node;
    delPtr = NULL;
    temp = head;
    curr = head;

    while(curr->data != delData && curr != NULL){
        temp = curr;
        curr = curr->next;
    }
    if(curr == NULL){
        cout<<delData<<" is not in the List"<<endl;
        delete delPtr;
    }
    else{
        delPtr = curr;
        curr = curr->next;
        temp->next = curr;
        if(delPtr == head){
            head = head->next;
            temp = NULL;
        }
        delete delPtr;
        cout<<"The value "<<delData<<" was deleted"<<endl;
    }

}

void List::printData(){

    nodePtr n = new node;
    if(head != NULL){
        n = head;
        while(n != NULL){
            cout<<n->data<<" ";
            n = n->next;
        }
        cout<<endl;
    }
    else{
        cout<<"List is empty"<<endl;
    }
}