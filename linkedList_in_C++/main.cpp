#include "list.cpp"

int main(){

    List list;
    list.addNode(3);
    list.addNode(4);
    list.addNode(5);
    list.printData();
    list.delNode(4);
    list.delNode(5);
    list.delNode(2);
    list.printData();
    return 0;

}