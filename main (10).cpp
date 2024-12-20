#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int getMax(const vector<int>& arr) {
    int max = arr[0];
    for (int i = 1; i < arr.size(); i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void countSort(vector<int>& arr, int n, int exp) {
    vector<int> output(n);
    vector<int> count(10, 0);

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(vector<int>& arr) {
    int n = arr.size();
    int m = getMax(arr);

    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

void bucketSort(vector<int>& arr) {
    int n = arr.size();
    vector<vector<int>> buckets(n); 

    int minVal = *min_element(arr.begin(), arr.end());
    int maxVal = *max_element(arr.begin(), arr.end());

    for (int i = 0; i < n; i++) {
        int bucketIndex = (n * (arr[i] - minVal)) / (maxVal - minVal);
        buckets[bucketIndex].push_back(arr[i]); 
    }

    for (auto& bucket : buckets) {
        sort(bucket.begin(), bucket.end()); 
    }

    int index = 0;
    for (auto& bucket : buckets) {
        for (int num : bucket) {
            arr[index++] = num;
        }
    }
}

void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> data = {170, 45, 75, 90, 802, 24, 2, 66};

    cout << "Unsorted Array: ";
    printArray(data);

    vector<int> data_radix = data;
    radixSort(data_radix);
    cout << "Radix Sort: ";
    printArray(data_radix);

    vector<int> data_bucket = data;
    bucketSort(data_bucket);
    cout << "Bucket Sort: ";
    printArray(data_bucket);

    return 0;
}