//이재환 22400583 

#include <iostream>
#include <string>
using namespace std; 
#define SIZE 100

class op_stack{ 
    char s[SIZE]; 
    int top; 

    public: 
        op_stack(); 
        void push (char x); 
        char pop(); 
        bool empty(); 
        char top_element(); 
}; 

op_stack:: op_stack(){ 
    top = 0;
}

void op_stack:: push(char x){ 
    s[top] = x; 
    top++; 
}

char op_stack:: pop(){ 
    top--; 
    return(s[top]); 
}

bool op_stack:: empty(){ 
    return (top == 0); 
}

char op_stack:: top_element(){ 
    return(s[top-1]); 
}

int main(){ 

    string str; 
    int size; 

    cin >> str; 
    size = str.size() / 2; 

    return 0; 
}