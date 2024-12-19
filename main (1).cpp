#include <iostream>
using namespace std;

void printFibonacci(int terms) {
    int t1 = 0, t2 = 1, nextTerm;

    cout << "Fibonacci Sequence: " << t1 << ", " << t2;
    for (int i = 3; i <= terms; i++) {
        nextTerm = t1 + t2;
        cout << ", " << nextTerm;
        t1 = t2;
        t2 = nextTerm;
    }
    cout << endl;
}

int main() {
    int terms;

    cout << "Enter the number of terms: ";
    cin >> terms;

    if (terms < 1) {
        cout << "Number of terms should be at least 1!" << endl;
    } else {
        printFibonacci(terms);
    }

    return 0;
}
