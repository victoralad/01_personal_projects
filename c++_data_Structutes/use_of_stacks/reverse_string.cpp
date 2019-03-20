#include <bits/stdc++.h> 
using namespace std;


void reverse_string(char* C, int size){
    stack<char> S;
    for(int i=0; i < size; i++){
        S.push(C[i]);
    }
    for(int i=0; i < size; i++){
        C[i] = S.top();
        S.pop();
    }

}

void rec_reverse_string(char* C, int size){
    char temp; 
    int len = strlen(C) - size;

    if(size == 0){
        return;
    }
    else{
        size--;
        temp = C[len];
        len++;
        rec_reverse_string(C, size);
        C[size] = temp;
        
    }

}

int main(){
    string str;
    std::cout << "Please enter the string you want to reverse" << "\n\n";
    std::cin >> str;
    int size = str.length();
    char C[size];
    strcpy(C, str.c_str()); 
    //reverse_string(C, size);
    rec_reverse_string(C, size);
    std::cout << C << "\n\n";
    return 0;
}