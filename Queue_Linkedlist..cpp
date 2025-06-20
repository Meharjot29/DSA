#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

void enqueue(int x) {
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = NULL;
    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue() {
    if (front == NULL) {
        cout << "Underflow\n";
    } else {
        Node* temp = front;
        front = front->next;
        delete temp;
    }
}

void traverse() {
    if (front == NULL) {
        cout << "Queue is empty\n";
        return;
    }

    Node* temp = front;
    cout << "Queue elements: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of elements to enqueue: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        enqueue(x);
    }

    cout << "After enqueue:\n";
    traverse();

    dequeue();  
    cout << "After dequeue:\n";
    traverse();

    return 0;
}
