#include <iostream>
using namespace std;

int main() {
    int n, sum = 0;

    cout << "Enter a positive integer: ";
    cin >> n;

    if (n <= 0) {
        cout << "Please enter a positive integer." << endl;
    } else {
        for (int i = 1; i <= n; i++) {
            sum += i;
        }
        cout << "The sum of natural numbers up to " << n << " is: " << sum << endl;
    }

    return 0;
}
