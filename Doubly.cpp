#include <iostream>
using namespace std;

struct node {
    int data;
    node *prev, *next;
};

node *start = NULL, *tail = NULL;

void insert_beg(int v) {
    node *nn = new node;
    nn->data = v;
    nn->prev = NULL;
    nn->next = start;
    if (start != NULL)
        start->prev = nn;
    else
        tail = nn;
    start = nn;
}

void insert_end(int v) {
    node *nn = new node;
    nn->data = v;
    nn->next = NULL;
    nn->prev = tail;
    if (tail != NULL)
        tail->next = nn;
    else
        start = nn;
    tail = nn;
}

void insert_after(int v, int a) {
    if (start == NULL) {
        cout << "No element\n";
        return;
    }

    node *temp = start;
    while (temp != NULL) {
        if (temp->data == a) {
            node *nn = new node;
            nn->data = v;
            nn->next = temp->next;
            nn->prev = temp;
            if (temp->next != NULL)
                temp->next->prev = nn;
            else
                tail = nn;
            temp->next = nn;
            return;
        }
        temp = temp->next;
    }
    cout << "\n" << a << " not found\n";
}

void traverse() {
    node *temp = start;
    while (temp != NULL) {
        cout << temp->data << "\t";
        temp = temp->next;
    }
    cout << endl;
}

void delbeg() {
    if (start == NULL) {
        cout << "Nothing in list\n";
        return;
    }
    node *loc = start;
    start = start->next;
    if (start != NULL)
        start->prev = NULL;
    else
        tail = NULL;
    delete loc;
}

void delend() {
    if (tail == NULL) {
        cout << "Nothing in list\n";
        return;
    }
    node *loc = tail;
    tail = tail->prev;
    if (tail != NULL)
        tail->next = NULL;
    else
        start = NULL;
    delete loc;
}

void deletion_ele(int p) {
    node *temp = start;
    while (temp != NULL) {
        if (temp->data == p) {
            if (temp == start) {
                delbeg();
            } else if (temp == tail) {
                delend();
            } else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp;
            }
            return;
        }
        temp = temp->next;
    }
    cout << p << " not found in list\n";
}

void searching(int s) {
    node *temp = start;
    while (temp != NULL) {
        if (temp->data == s) {
            cout << "\n" << s << " element found\n";
            return;
        }
        temp = temp->next;
    }
    cout << "\n" << s << " Not found\n";
}

int main() {
    int s;
cout << " Insertion from starting: " ;
    insert_beg(10);
    insert_beg(20);
    insert_beg(30);
    traverse();
    
cout << " Insertion from ending: " ;
    insert_end(50);
    insert_end(60);
    traverse();
    
cout << " Deletion from starting: " ;
    delbeg();
    traverse();
    
cout << " Deletion from ending: " ;
    delend();
    traverse();

cout << " Deletion from Middle: " ;
    deletion_ele(50);
    traverse();

    cout << "Enter the element you want to search: ";
    cin >> s;
    searching(s);

    return 0;
}

