#include <bits/stdc++.h> 
using namespace std;

int len = 0;

bool balanced(char* parIn, int sizeIn){
    stack<char> S;
    for(int i=0; i<sizeIn; i++){
        if((parIn[i] == '{')||(parIn[i] == '(')||(parIn[i] == '[')){
            S.push(parIn[i]);
        }
        else if (parIn[i] == '}'){
            if(S.empty() || (S.top() != '{')){
                return false;
            }
            else{
                S.pop();
            }
        }
        else if (parIn[i] == ')'){
            if(S.empty() || (S.top() != '(')){
                return false;
            }
            else{
                S.pop();
            }
        }
        else if (parIn[i] == ']'){
            if(S.empty() || (S.top() != '[')){
                return false;
            }
            else{
                S.pop();
            }
        }
    }
    return S.empty();
}

bool bal_recursion(char* parIn, int sizeIn){
    
    if(len == sizeIn){
        return true;
    }
    else{
        char temp = parIn[len];
        
        bal_recursion(parIn, sizeIn);
        len++;
    }
}

int main(){
    string str = "[(a+b)(c+d){]";
    int size = str.length();
    char par[size];
    strcpy(par, str.c_str()); 
    bool bal_par;
    bal_par = balanced(par, size);
    if(bal_par){
        std::cout << "Balanced" << "\n";
    }
    else{
        std::cout << "NOT balanced" << "\n";
    }
    return 0;
}

//try using recursion for this