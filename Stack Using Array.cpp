#include <iostream>
using namespace std;

int st[20], tos = -1;
int max_size = 10;

void Push1(int d) {
    if (tos >= max_size - 1) {
        cout << "overflow\n";
    } else {
        st[++tos] = d;
    }
}

void pop1() {
    if (tos == -1) {
        cout << "undo\n";
    } else {
        tos--;
    }
}

void tra() {
    for (int i = 0; i <= tos; i++) {
        cout << st[i] << endl;
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
Push1(50);
    cout << "After Pushing: " << endl;
    tra();
pop1();
pop1();
    pop1();
    cout << "After popping: " << endl;
    tra();

    return 0;
}
