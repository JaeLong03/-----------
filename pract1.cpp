#include <iostream>
#include <string>

using namespace std;

class node {
public:
        string   name;
        double      score;
        node *link;
        void   set_data(string   s, double n);
};

void   node::set_data(string s, double n) {
           name = s;
           score = n;
}

class my_list {
        node   *head;
public:
        my_list();
        void add_to_head(node   t);
        double   score_sum();
        int   num_nodes();
        double   get_score(string tname);
        int count_high_scores();
        void show_all_data();
};

my_list::my_list()
{
        head = NULL;
}


void my_list::add_to_head(node t) {
        node   *p;
        p = new   node;
        (*p) = t;
        p->link = head;
        head = p;
}

int   my_list::num_nodes()
{
        node   *t;
        int count = 0;
        for (t = head; t != NULL; t = t->link)
        count++;
        return count;
}

double   my_list::score_sum() 
{
    node   *t;
    double total = 0;
    for (t = head; t != NULL; t = t->link)
        total += t->score; 
    return total; 
}

int   my_list::count_high_scores()
{
    node   *t;
    int count = 0;
    for (t = head; t != NULL; t = t->link){ 
        if(t -> score >= 80)
            count++; 
    }
    return count; 
}

double   my_list::get_score(string tname)
{
    node   *t;
    double tmp = -1.0;
    for (t = head; t != NULL; t = t->link){ 
        if(tname == t -> name){ 
            tmp = t -> score; 
            break; 
        }
    }
    return tmp; 
}

void my_list::show_all_data()
{
        node *p;

        for ( p = head; p != NULL; p = p->link)
                cout << p->name << " : " << p->score << endl;

}

int main()
{
my_list    a;
node   tmp;
        tmp.set_data("Kim", 83.5);
        a.add_to_head(tmp);
        tmp.set_data("Lee", 58.2);
        a.add_to_head(tmp);
        tmp.set_data("Park", 91.3);
        a.add_to_head(tmp);
        tmp.set_data("Choi", 55.1);
        a.add_to_head(tmp);
        tmp.set_data("Ryu", 77.1);
        a.add_to_head(tmp);
        tmp.set_data("Yang", 41.3);
        a.add_to_head(tmp);
        tmp.set_data("Hong", 78.2);
        a.add_to_head(tmp);

        cout << "\nThe list before the test \n";
        a.show_all_data();

        cout << "\nThe Number of nodes : " << a.num_nodes() << endl;

        double average = a.score_sum() / a.num_nodes();

        cout << "The Average : " << average << endl;

        cout << "The number of high scores(higher than 80) : " << a.count_high_scores() << endl;

        cout << "Choi's score : " << a.get_score("Choi") << endl;

        return 0;

}
