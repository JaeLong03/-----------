#include <iostream>
using namespace std;

class weight{ 
    int kg, gram; 

    public: 
    void set_weight(int n1, int n2); 
    int get_weight(); 
    bool isheavy(); 
    void add_grams(int n); 
}; 

void weight:: set_weight(int n1, int n2){
    kg = n1; 
    gram = n2; 
}

int weight:: get_weight(){ 
    int result; 
    
    result = kg * 1000 + gram; 
    return result; 
}

bool weight:: isheavy(){ 
    if(kg >= 10)
        return true; 
    else
        return false; 
}

void weight:: add_grams(int n){ 
    gram += n; 
    if(gram >= 1000){ 
        kg++; 
        gram -= 1000; 
    }
}


weight add_weight(weight w1, weight w2); 


int main(){ 
    weight w1, w2, w3; 
    w1.set_weight(12, 800);
    if(w1.isheavy())
        cout << "Heavy.\n"; 
    else   
        cout << "Light.\n";
    
    w2.set_weight(2, 900);
    w2.add_grams(500);
    w3 = add_weight(w1, w2);
    
    cout << w3.get_weight() << " grams\n"; 
}

weight add_weight(weight w1, weight w2){ 
    weight w3; 

    int sum = w1.get_weight() + w2.get_weight(); 
    w3.set_weight(sum/1000, sum%1000); 
    return w3; 
}