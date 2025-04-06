#include <iostream> 
using namespace std; 

class node{ 
    public: 
        string name; 
        double score; 
        node *link; 
        void set_data(string s, double d);
}; 

void node:: set_data(string s, double d){ 
    name = s; 
    score = d; 
}


class my_list {
    node* head, * tail;

    public:
        my_list();
        void add_to_head(node t);
        void add_to_tail(node t);
        node delete_from_head();
        int num_nodes();
        double score_sum();
        double get_score(string tname);
        int remove_a_node(string tname);
};

my_list:: my_list(){ 
    head = tail = NULL;
}

void my_list:: add_to_head(node t){ 
    node *p; 
    p = new node; 
    (*p) = t; 
    p-> link = head; 
    head = p; 
    if(tail == NULL)
        tail = p; 
}

void my_list:: add_to_tail(node t){ 
    node *p; 
    p = new node; 
    (*p) = t; 
    p -> link = NULL; 
    if(tail != NULL)
        tail -> link = p; 
    else 
        head = p; 
    tail = p; 
}

node my_list:: delete_from_head(){ 
    node   temp;
    node   *t;
    t = head;
    temp = *head;
    head = head->link;
    delete   t;
    if (head == NULL)  // 삭제 후 empty가 되면, tail값도 조정
        tail = NULL;
    return   temp;
}

int my_list:: num_nodes(){ 
    node   *t;
    int count = 0;
    for (t = head; t != NULL; t = t->link)
        count++;
    return   count;
}

double my_list:: score_sum(){ 
    node   *t;
    double total = 0;
    for (t = head; t != NULL; t = t->link)
        total += t->score; 
    return total; 
}

double my_list:: get_score(string tname){ 
    node   *t;
    double tmp = 0;
    for (t = head; t != NULL; t = t->link){ 
        if(tname == t -> name){ 
            tmp = t -> score; 
            break; 
        }
    }
    return tmp; 
}

int my_list:: remove_a_node(string tname){ 
    node *t;
    node *prev; 
    for (t = head; t != NULL; t = t->link){ 
        if (t->name == tname){
            if (prev == NULL) { // 첫 번째 노드를 삭제할 경우
                head = t->link;
                if (t == tail) // 리스트에 하나만 있었던 경우
                    tail = NULL;
            } else {
                prev->link = t->link;
                if (t == tail)
                    tail = prev;
            }
            delete t;
            return 1; // 삭제 성공
        }
        prev = t;
    }
    
    return 0; 
}

int main( ){
    my_list  a;
    node   tmp;
    tmp.set_data("Kim", 83.5);
    a.add_to_head(tmp);
    tmp.set_data("Lee", 78.2);
    a.add_to_head(tmp);           // head 위치로 2개의 원소 추가
    cout << a.num_nodes() << ":" << a.score_sum() << endl;  // 1단계 점검
    tmp.set_data("Park", 91.3);   
    a.add_to_tail(tmp);             // tail 위치로 1개의 원소 추가
    cout << a.num_nodes() << " : " << a.score_sum() << endl;  //2단계 점검
    tmp = a.delete_from_head();cout << tmp.name << "is delted.\n";   // 3단계 점검
    tmp.set_data("Choi", 85.1);   
    a.add_to_tail(tmp);              
    tmp.set_data("Ryu", 94.3);   
    a.add_to_head(tmp);             // 2개의 원소 추가
    cout << a.num_nodes()<< " : " << a.score_sum() << endl;
    cout << "Park's score : " << a.get_score("Park")<< endl;  // 4단계 점검
    if ( a.remove_a_node("Kim") == 1)
    cout << "Kim is deleted from the list.";     // 5단계 점검
    cout << a.num_nodes()<< " : "<< a.score_sum() << endl;  // 최종 점검
    return 0;
}