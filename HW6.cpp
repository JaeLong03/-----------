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

class my_tree{ 
    public: 
        int node_count; 
        node *root; 
        my_tree(); 
        int insert_root(node t); 
        int insert_left(string name, node t); 
        int insert_right(string name, node t); 
        int n_d2_nodes();
        int n_d1_nodes();
        int n_leaf_nodes(); 
};

int node_insert_left(node* p, string tname, node tnode);
int node_insert_right(node* p, string tname, node tnode);

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


int main()
{
        my_tree  thetree;
        node  tmp;
        tmp.set_data("Kim", 81.1);
        thetree.insert_root(tmp);
        tmp.set_data("Lee", 86.2);
        thetree.insert_left("Kim", tmp);
        tmp.set_data("Park", 79.4);
        thetree.insert_right("Kim", tmp);
        tmp.set_data("Choi", 77.8);
        thetree.insert_left("Lee", tmp);
        tmp.set_data("Ryu", 92.2);
        thetree.insert_right("Lee", tmp);
        tmp.set_data("Cho", 68.6);
        thetree.insert_right("Park", tmp);
        tmp.set_data("Yang", 72.8);
        thetree.insert_left("Ryu", tmp);
        tmp.set_data("Jung", 62.3);
        thetree.insert_left("Cho", tmp);

        cout << "The number of degree-2 nodes : " << thetree.n_d2_nodes() << endl;  // degree 2인 node 수
        cout << "The number of degree-1 nodes : " << thetree.n_d1_nodes() << endl; // degree 1인 node 수
        cout << "The number of leaf nodes : " << thetree.n_leaf_nodes() << endl;      // leaf node 수

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
