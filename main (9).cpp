#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; 
    int i = (low - 1); 

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++; 
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void countingSort(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> count(k + 1, 0); 
    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    for (int i = 1; i <= k; i++)
        count[i] += count[i - 1];

    vector<int> output(n);
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> data = {64, 34, 25, 12, 22, 11, 90};

    cout << "Unsorted Array: ";
    printArray(data);

    vector<int> data_quick = data; 
    quickSort(data_quick, 0, data_quick.size() - 1);
    cout << "Quick Sort: ";
    printArray(data_quick);

    vector<int> data_count = {1, 4, 1, 2, 7, 8, 2}; 
    countingSort(data_count, 8); 
    cout << "Counting Sort: ";
    printArray(data_count);

    return 0;
}