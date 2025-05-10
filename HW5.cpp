//이재환 22400583
#include <iostream> 
using namespace std; 

class node{ 
    public: 
        string name; 
        double score; 
        node *left, *right;
        void set_data(string tname, double n); 
}; 

void node:: set_data(string tname, double n){ 
    name = tname; 
    score = n; 
}


class nstack {
    public:
        node* stack[100];
        int top;
        nstack(); 
        bool stack_empty(); 
        void push(node* t); 
        node* pop(); 
};

nstack:: nstack(){ 
    top = 0; 
}

bool nstack:: stack_empty(){ 
    return top == 0; 
}

void nstack:: push(node*t){ 
    if (top == 100) return; 
    stack[top] = t;
    top++; 
}

node* nstack:: pop(){ 
    if (stack_empty()) return NULL; 
    return stack[--top];
}

class my_queue{ 
    public: 
        int front, rear; 
        node* Q[100]; 
        my_queue(); 
        void insert_q(node *t);
        node *delete_q(); 
        bool q_empty(); 
}; 

my_queue:: my_queue(){ 
    front = rear = 0;
}

void my_queue:: insert_q(node *t){ 
    if(!((rear +1)%100 == front)){ 
        Q[rear] = t; 
        rear = (rear +1)%100; 
    }
}

bool my_queue:: q_empty(){ 
    if(rear == front) return true; 
    else return false; 
}

node* my_queue:: delete_q(){ 
    node* tmp; 
    if(!q_empty()){ 
        tmp = Q[front]; 
        front = (front+1) % 100; 
    }
    return tmp; 
}

class my_tree{ 
    public: 
        int node_count; 
        node *root; 
        my_tree(); 
        int insert_root(node t); 
        int insert_left(string name, node t); 
        int insert_right(string name, node t); 

        void print_data_inorder();
        void nonrecursive_inorder();
        void print_data_levelorder();
}; 

int node_insert_left(node* p, string tname, node tnode);
int node_insert_right(node* p, string tname, node tnode);
void printInorder(node *t); 
void printNon(node *t); 
void copy_tree(my_tree &t1, my_tree t2); 
node* make_copy(node *p); 
bool equal_tree(my_tree t1, my_tree t2); 
bool equal_test(node *p1, node*p2); 

my_tree:: my_tree(){ 
    node_count = 0; 
    root = NULL; 
}

int my_tree:: insert_root(node t){ 
    if(root != NULL) return 0; 
    node *p; 
    p = new node; 
    (*p) = t; 
    p -> left = NULL; 
    p -> right = NULL; 
    root = p; 
    node_count++; 
    return 1; 
}

int my_tree:: insert_left(string name, node t){ 
    int result; 

    result = node_insert_left(root, name, t); 
    if(result == 1) node_count++; 
    return result; 
}

int my_tree:: insert_right(string name, node t){ 
    int result; 

    result = node_insert_right(root, name, t); 
    if(result == 1) node_count++; 
    return result; 
}

void my_tree:: print_data_inorder(){ 
    printInorder(root); 
}

void my_tree:: nonrecursive_inorder(){ 
    nstack s1;
    node *t;
    t = root;
    while (1){
        while (t != NULL) {
            s1.push(t);
            t = t->left;
        }
        if (s1.stack_empty() ) return;
        t = s1.pop();
        cout << t->name << " : " << t->score << endl;
        t = t->right;
    }
}

void my_tree:: print_data_levelorder(){ 
    my_queue a1; 
    node *t; 
    if(root == NULL) return; 
    a1.insert_q(root); 
    while(1){ 
        if(a1.q_empty()) return; 
        t = a1.delete_q(); 
        cout << t->name << ":" << t->score << endl; 
        if(t->left != NULL) a1.insert_q(t->left); 
        if(t->right != NULL) a1.insert_q(t->right); 
    }
}


int main(){
    my_tree  thetree;
    node  tmp;
    
    tmp.set_data("Kim", 8.1);
    thetree.insert_root(tmp);
    tmp.set_data("Lee", 6.5);
    thetree.insert_left("Kim", tmp);
    tmp.set_data("Park", 8.3);
    thetree.insert_right("Kim", tmp);
    tmp.set_data("Choi", 7.2);
    thetree.insert_left("Lee", tmp);
    tmp.set_data("Ryu", 9.0);
    thetree.insert_right("Lee", tmp);
    tmp.set_data("Cho", 7.7);
    thetree.insert_right("Park", tmp);
    
    cout << "\nNon-recursive Inorder Result \n";
    thetree.nonrecursive_inorder();
    
    cout << "\nLevel-Order traversal Result \n";
    thetree.print_data_levelorder();
    
    my_tree tree2;
    copy_tree(tree2, thetree);
    cout << "\nThe inorder traversal Result of the new tree \n";
    tree2.print_data_inorder();
    
    if (equal_tree(tree2, thetree) ) cout << "Yes\n";
    else cout << "No\n";
    
    tmp.set_data("Youn", 7.7);
    thetree.insert_right("Cho", tmp);
    if (equal_tree(tree2, thetree) ) cout << "Yes\n";
    else cout << "No\n";

    return 0;

}      

int node_insert_left(node* p, string tname, node tnode){ 
    if(p == NULL) return 0; 
    if(p->name == tname){ 
        if(p->left != NULL) return -1; 
        node *t; 
        t = new node; 
        (*t) = tnode; 
        t -> left = NULL; 
        t -> right = NULL; 
        p->left = t; 
        return 1; 
    }
    else{ 
        int result = node_insert_left(p->left, tname, tnode); 
        if(result != 0)
            return result; 
        return node_insert_left(p->right, tname, tnode); 
    }
}

int node_insert_right(node* p, string tname, node tnode){ 
    if(p == NULL) return 0; 
    if(p->name == tname){ 
        if(p->right != NULL) return -1; 
        node *t; 
        t = new node; 
        (*t) = tnode; 
        t -> left = NULL; 
        t -> right = NULL; 
        p->right = t; 
        return 1; 
    }
    else{ 
        int result = node_insert_right(p->right, tname, tnode); 
        if(result != 0)
            return result; 
        return node_insert_right(p->left, tname, tnode); 
    }
}

void printInorder(node *t){ 
    if (t == NULL) return;
    printInorder(t->left); 
    cout << t->name << " " << t->score << endl; 
    printInorder(t->right); 
}


void copy_tree(my_tree &t1, my_tree t2){ 
    t1.node_count = t2.node_count; 
    t1.root = make_copy(t2.root); 
}

node* make_copy(node *p){ 
    node *t; 

    if(p == NULL) return NULL; 
    t = new node;
    *t = *p; 
    t->left = make_copy(p->left); 
    t->right = make_copy(p->right); 
    return t; 
}

bool equal_tree(my_tree t1, my_tree t2){ 
    if(t1.node_count!= t2.node_count) return false; 
    return equal_test(t1.root, t2.root); 
}

bool equal_test(node *p1, node*p2){ 
    if((p1 == NULL) && (p2 == NULL)) return true; 
    if(p1 == NULL) return false; 
    if(p2 == NULL) return false; 
    if(p1->name != p2->name) return false; 
    if(p1->score != p2->score) return false; 

    if(equal_test(p1->left, p2->left) && equal_test(p1->right, p2->right)) return true; 
    else return false; 
}
