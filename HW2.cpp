// 이재환 22400583

#include <iostream> 
using namespace std; 
#include <string> 
#define SIZE 100
#define EOS '$'

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

bool is_operand(char ch); 
int get_precedence(char op); 

int main(){ 
    string input, output; 
    op_stack stack1; 
    int i; 

    cout << "Input an infix expression to convert : "; 
    cin >> input; 
    input += EOS; 
    
    stack1 = op_stack(); 
    stack1.push(EOS); 
    for (i = 0; i < input.size(); i++) {
        if(input[i] == EOS)
            break;

        if (is_operand(input[i])) {
            output += input[i];
        } else {
            if (input[i] == '(') {
                stack1.push(input[i]);
            } else if (input[i] == ')') {
                while (!stack1.empty() && stack1.top_element() != '(') {
                    output += stack1.pop();
                }
                if (!stack1.empty()) stack1.pop();
            } else {
                while (!stack1.empty() && get_precedence(input[i]) <= get_precedence(stack1.top_element())) {
                    output += stack1.pop();
                }
                stack1.push(input[i]);
            }
        }
    }

    while (!stack1.empty() && stack1.top_element() != EOS) {
        output += stack1.pop();
    }


    cout << output << endl; 
    return 0; 
}

bool is_operand(char ch){ 
    if((ch == '(') || (ch == ')') ||
    (ch == '+') ||   (ch == '-') ||
    (ch == '*') ||   (ch == '/') ||
    (ch == '%') ||   (ch == '$')){ 
        return false; 
    }
    return true; 
}

int get_precedence(char op){ 
    if((op == '$') || (op == '('))
        return 0; 
    if((op == '+') || (op == '-'))
        return 1; 
    if((op == '*') || (op == '/') || (op == '%'))
        return 2; 
       
    return 0; 
}



