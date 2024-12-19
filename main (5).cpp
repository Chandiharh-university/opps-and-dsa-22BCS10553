#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
    const int numStudents = 3; 
    int id[numStudents];
    string name[numStudents];
    float marks[numStudents];

    cout << "Enter details for " << numStudents << " students:\n";
    for (int i = 0; i < numStudents; i++) {
        cout << "\nStudent " << i + 1 << ":\n";
        cout << "ID: ";
        cin >> id[i];
        cin.ignore(); 
        cout << "Name: ";
        getline(cin, name[i]);
        cout << "Marks: ";
        cin >> marks[i];
    }

    cout << "\n-----------------------------------------------\n";
    cout << "| " << setw(5) << "ID" << " | " << setw(15) << "Name" << " | " << setw(10) << "Marks" << " |\n";
    cout << "-----------------------------------------------\n";
    for (int i = 0; i < numStudents; i++) {
        cout << "| " << setw(5) << id[i] << " | " << setw(15) << name[i] << " | " << setw(10) << marks[i] << " |\n";
    }
    cout << "-----------------------------------------------\n";

    return 0;
}
