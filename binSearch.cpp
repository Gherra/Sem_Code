#include <iostream>
#include<vector>



using namespace std;

int binSearch(vector<int> arr, int low, int high, int x) {
    if (high >= low) { // Base case: when the search range is valid
        // int mid = (low + high) / 2; // Find the middle index
        // Calculate the middle index. Didn't use (l + r) / 2 to avoid integer overflow
        int mid = low + (high - low) / 2;
        if (arr[mid] == x) { // If the middle element is the target, return its index
            return mid;
        } else if (arr[mid] > x) { // If the target is smaller, search the left half
            return binSearch(arr, low, mid - 1, x);
        } else { // If the target is larger, search the right half
            return binSearch(arr, mid + 1, high, x);
        }
    }
    return -1; // Base case: when the element is not found
}

int main(){
    vector<int>arr = {1, 2, 3, 4, 5, 6, 7};
    int reqIndex = binSearch(arr, 0, arr.size(), 6);

    cout << reqIndex << '\n';
    return 0;
}