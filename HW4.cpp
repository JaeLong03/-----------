#include <iostream> 
using namespace std; 

class node{ 
    public: 
        string name; 
        double score; 
        node *left, *right;
        void set_data(string tname, double n); 
}; 

class my_tree{ 
    public: 
        int node_count; 
        node *root; 
        my_tree(); 
        int insert_root(node t); 
        int insert_left(string name, node t); 
        int insert_right(string name, node t); 

        double score_sum(); 
        double score_average(); 
        void print_data_inorder(); 
        void print_data_preorder(); 
        void print_data_postorder(); 
}; 

void node:: set_data(string tname, double n){ 
    name = tname; 
    score = n; 
}

int node_insert_left(node* p, string tname, node tnode);
int node_insert_right(node* p, string tname, node tnode);
double sum_allnodes(node *t); 
void printInorder(node *t); 
void printPreorder(node *t); 
void printPostorder(node *t); 

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

double my_tree:: score_sum(){
    return sum_allnodes(root); 
}

double my_tree:: score_average(){ 
    return sum_allnodes(root) / node_count;
}

void my_tree:: print_data_inorder(){ 
    printInorder(root); 
}

void my_tree:: print_data_preorder(){ 
    printPreorder(root); 
}

void my_tree:: print_data_postorder(){ 
    printPostorder(root); 
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
    
    cout<< "Score Sum : " << thetree.score_sum() << "\n";
    cout<< "Score Average : " << thetree.score_average() << "\n";
    
    cout <<"\nInorder Traversal Result \n";
    thetree.print_data_inorder();
    cout << "\nPreorder Traversal Result \n";
    thetree.print_data_preorder();
    cout << "\nPostorder Traversal Result \n";
    thetree.print_data_postorder();
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

double sum_allnodes(node *t){ 
    if(t == NULL) return 0; 
    return sum_allnodes(t->left) + t->score + sum_allnodes(t->right); 
}

void printInorder(node *t){ 
    if (t == NULL) return;
    printInorder(t->left); 
    cout << t->name << " " << t->score << endl; 
    printInorder(t->right); 
}

void printPreorder(node *t){ 
    if (t == NULL) return;
    cout << t->name << " " << t->score << endl; 
    printPreorder(t->left); 
    printPreorder(t->right); 
}

void printPostorder(node *t){ 
    if (t == NULL) return;
    printPostorder(t->left); 
    printPostorder(t->right); 
    cout << t->name << " " << t->score << endl; 
}


