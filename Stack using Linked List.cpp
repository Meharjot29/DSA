#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
}
*temp ;
Node* top = NULL;

void Push1(int d) {
    Node* newNode = new Node();
    newNode->data = d;
    newNode->next = top;
    top = newNode;
}

void pop1() {
    if (top == NULL) {
        cout << "undo\n";
    } else {
         temp = top;
        top = top->next;
        delete temp;
    }
}

void tra() {
     temp = top;
    while (temp != NULL) {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        Push1(x);
    }

    Push1(10);
    Push1(50);
    Push1(70);

    cout << "After Pushing: " << endl;
    tra();

    pop1();
    cout << "After popping: " << endl;
    tra();

    return 0;
}
