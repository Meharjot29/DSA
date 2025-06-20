#include <iostream>
#define SIZE 100
using namespace std;

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int x) {
    if (rear == SIZE - 1) {
        cout << "Overflow\n";
    } else {
        if (front == -1) front = 0;
        queue[++rear] = x;
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        cout << "Underflow\n";
    } else {
        front++;
    }
}

void traverse() {
    if (front == -1 || front > rear) {
        cout << "Queue is empty\n";
    } else {
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << "\n";
    }
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

    cout << "After Enqueue: \n";
    traverse();

    dequeue();  
    cout << "After Dequeue: \n";
    traverse();

    return 0;
}

