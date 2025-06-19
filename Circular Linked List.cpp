#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
} *start = NULL, *last = NULL;

void insert1(int v) {
    node *nn = new node;
    nn->data = v;
    if (start == NULL) {
        start = nn;
        nn->next = nn;
        last = nn;
    } else {
        last->next = nn;
        nn->next = start;
        last = nn;
    }
}

void traverse() {
    if (start == NULL) {
        cout << "List is empty\n";
        return;
    }
    node *temp = start;
    do {
        cout << temp->data << endl;
        temp = temp->next;
    } while (temp != start);
}

void deletion(int v) {
    if (start == NULL) {
        cout << "List is empty\n";
        return;
    }

    node *temp = start, *prev = last;
    do {
        if (temp->data == v) {
            if (temp == start && temp == last) {
                // Only one node
                delete temp;
                start = last = NULL;
            } else {
                if (temp == start)
                    start = start->next;
                if (temp == last)
                    last = prev;
                prev->next = temp->next;
                delete temp;
            }
            cout << v << "\t deleted successfully\n";
            return;
        }
        prev = temp;
        temp = temp->next;
    } while (temp != start);

    cout << v << " not found in list\n";
}

int main() {
    int n;
    cout << "Elements added:" << endl;
    insert1(10);
    insert1(20);
    insert1(30);
    insert1(40);
    traverse();

    cout << "\nEnter element to delete: ";
    cin >> n;
    deletion(n);
      cout << "Final Elements: \n";
    traverse();

    return 0;
}