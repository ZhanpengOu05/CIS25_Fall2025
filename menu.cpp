#include <iostream>
using namespaces std;
int main(){
    int choice;
    cout<<"1.Add Item\n2. View Items\n3. Exit\n;"
    cin>>choice;

    if (choice == 1) cout << "item added!\n";
    else if (choice == 2) cout << "Displying items...\n";
    else if (choice == 3) cout <<" Exiting...\n";
    else cout << "Invalid option.\n";
    return 0;
}