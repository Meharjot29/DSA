#include <iostream>
using namespace std;

struct Node {
    int reg_no;
    int marks;
    string name;
    int section;
    Node* next;
}
*nn , *temp ,*head ;

void insert_ele(int m, int r, int section, string name) {
Node* nn = new Node;
nn->reg_no = r;
nn->marks = m;
nn->section = section;
nn->name = name;
nn->next = NULL;

if (head == NULL) {
        head = nn;
    }
    else
    {
      temp = head;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = nn;
    }
}

void delete_ele() {
    if (head == NULL)
        {
        cout << "No Element" << endl;
    } else {
        temp = head;
        head = head->next;
        delete temp;
    }
}

void traverse() {
     temp = head;
    while (temp != NULL) {
            cout << "\n" << "Registration Number: " << temp->reg_no << "\n"<< " Marks: " << temp->marks << "\n" << " Name: " << temp->name << "\n" << " Section: " << temp->section << endl;
        temp = temp->next;
    }
}

int main() {
    cout<< "Data of Students: " << endl;
insert_ele(1, 22, 123, "Garv");
insert_ele(2, 24, 123, "Vansh");
insert_ele(23, 20, 123, "Nitish");
traverse();

cout << "\n" ;
   cout<< "Data of Students after deletion: " << endl;
delete_ele();

traverse();

    return 0;
}
