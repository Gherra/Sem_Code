#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int findUnimodalPeak(vector<int>& arr, int l, int r) {
    // Base case: Single element
    if (l == r) {
        return l;
    }
    // Calculate the middle index. Didn't use (l + r) / 2 to avoid integer overflow
    int m = l + (r - l) / 2;

    cout << "Middle index: " << m << " Value: " << arr[m] << endl;

    // Check peak condition
    if (arr[m] > arr[m + 1] && arr[m] > arr[m - 1]) {
        return m;
    }
    // Move to the right half if the right neighbor is greater
    else if (arr[m] < arr[m + 1]) {
        return findUnimodalPeak(arr, m + 1, r);
    }
    // Move to the left half otherwise
    else {
        return findUnimodalPeak(arr, l, m - 1);
    }
}



int main(){

    vector<int> arr = {5, 7, 8, 10, 9, 6, 4};

    int peakIndex = findUnimodalPeak(arr, 0,  arr.size() - 1);

    cout << peakIndex << endl;
    
    return 0;
}