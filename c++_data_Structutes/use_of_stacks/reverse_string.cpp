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
int main(){
    string str;
    std::cout << "Please enter the string you want to reverse" << "\n\n";
    std::cin >> str;
    int size = str.length();
    char C[size];
    strcpy(C, str.c_str()); 
    reverse_string(C, size);
    std::cout << C << "\n\n";
    return 0;
}