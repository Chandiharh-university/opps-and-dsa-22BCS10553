#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    int startIndex = 2; 

    if (startIndex < 0 || startIndex >= size) {
        cout << "Invalid start index." << endl;
        return 1;
    }

    cout << "Elements from index " << startIndex << ": ";
    for (int i = startIndex; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}