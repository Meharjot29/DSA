#include <iostream>
using namespace std;
int main(){
int ar[20], n, ar1[20],n1 , ar2[20], n2;

cout << "Enter the Number of Array1:" << endl;
cin >> n;


cout << " Enter the Elements: ";
for ( int i = 0 ; i < n ; i++){
   cin >> ar[i];
}


cout << " Enter Number of Array2:" << endl;
cin >> n1;

cout << "Enter the elements:" << endl;
for (int i = 0 ; i < n1; i++) {
    cin >> ar1[i];
}








int p;
cout << "Enter 1 to Merge" << endl;
cout << "Enter 2 to Concat" << endl;
cout << "Enter 3 to Reverse" << endl;
cout << "Enter 4 to Insert" << endl;

cin >> p;
switch(p){


case 1 :{
int k = n;
 for ( int i = 0; i < n1; i++){
    ar[k] = ar1[i];
    k++;
    }
 cout << "\n After Merging :";
 for ( int i = 0 ; i < k ; i++){
    cout << ar[i] ;
 }
 break;
}








case 2 :{
 int k = n;
 for ( int i = 0 ; i < n; i++){
    ar2[i] = ar[i];
 }
 for ( int i = 0 ; i < n1; i++){
    ar2[k] = ar1[i];
    k++;
     }
cout << "\n After Concat :";
 for ( int i = 0 ; i < k ; i++){
    cout << ar2[i] ;
 }
 break;
}










case 3:{
int start = 0;
int last = n1 - 1;
int temp;

for (int i = 0; i < n1 / 2; i++) {
temp = ar[start];
ar[start] = ar[last];
ar[last] = temp;
        start++;
        last--;
    }

cout << "\nReversed Array 1: ";
for (int i = 0; i < n1; i++) {
        cout << ar[i] ;
    }
break;
}

case 4: {
  int pos, element;
    cout << "Enter the position where you want to insert an element in Array1: ";
    cin >> pos;

    if (pos < 0 || pos > n) {
        cout << "Invalid position!" << endl;
        return 1; // Exit if invalid position
    }

    cout << "Enter the element to insert: ";
    cin >> element;

    // Shift elements to the right
    for (int i = n; i > pos; i--){
        ar[i] = ar[i - 1];
    }

    // Insert the element
    ar[pos] = element;
    n++; // Increase the size of the array

    // Display the array after insertion
    cout << "Array1 after insertion: ";
    for (int i = 0; i < n; i++){
        cout << ar[i];
    }
break;
}









 default : {
 cout << " Out of Syllbus" ;
 break;
 }
}

return 0;
}


