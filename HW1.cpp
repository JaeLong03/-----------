// 이재환 22400583

#include <iostream>
using namespace std;   

class Weight{ 
    int kg, gram; 

    public: 
    void set_weight(int n1, int n2); 
    int get_weight(); 
    bool isheavy(); 
    void add_grams(int n); 
}; 

void Weight:: set_weight(int n1, int n2){
    kg = n1; 
    gram = n2; 
}

int Weight:: get_weight(){ 
    int result; 
    
    result = kg * 1000 + gram; 
    return result; 
}

bool Weight:: isheavy(){ 
    if(kg >= 10)
        return true; 
    else
        return false; 
}

void Weight:: add_grams(int n){ 
    gram += n; 
    if(gram >= 1000){ 
        kg++; 
        gram -= 1000; 
    }
}


Weight add_weight(Weight w1, Weight w2); 


int main(){ 
    Weight w1, w2, w3; 
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

Weight add_weight(Weight w1, Weight w2){ 
    Weight w3; 

    int sum = w1.get_weight() + w2.get_weight(); 
    w3.set_weight(sum/1000, sum%1000); 
    return w3; 
}