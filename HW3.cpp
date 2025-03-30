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

void op_stack::push(char x) { 
    s[top] = x;  
    top++; 
}

char op_stack::pop() { 
    top--;  
    return s[top];  
}

bool op_stack:: empty(){ 
    return (top == 0); 
}

char op_stack:: top_element(){ 
    return(s[top-1]); 
}

bool is_Palin(string s); 

int main() { 
    string str; 

    cin >> str; 

    if (is_Palin(str)) { 
        cout << "Yes, it's a palindrome" << endl; 
    } else { 
        cout << "No, it's not a palindrome" << endl; 
    }

    return 0; 
}

bool is_Palin(string s) { 
    op_stack st;
    op_stack(); 
    int len = s.size();
    
    for (int i = 0; i < len / 2; i++) { 
        st.push(s[i]); 
    }

    int start_idx;

    if(len % 2 == 0) 
        start_idx = len / 2;
    else   
        start_idx = len / 2 + 1;

    for (int i = start_idx; i < len; i++) { 
        if (s[i] != st.pop()) { 
            return false; 
        }
    }
    
    return true; 
}