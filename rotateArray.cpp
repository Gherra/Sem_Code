#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> rotateArray(vector<int> &A, int B) {
        vector<int> ret; 
        int X = B % A.size();
        for (int i = 0; i < A.size() - X; i++) {
            ret.push_back(A[i + X]);
        }
        for(int i = 0 ; i < X ; i++){
            ret.push_back(A[i]);
        }
        return ret; 
    }
};

int main() {
    int n, B;
    
    // Input array size
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> A(n);

    // Input array elements
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // Input number of rotations
    cout << "Enter the number of rotations: ";
    cin >> B;

    // Create an object of the Solution class
    Solution sol;
    
    // Rotate the array
    vector<int> rotatedArray = sol.rotateArray(A, B);

    // Print the rotated array
    cout << "Rotated Array: ";
    for (int num : rotatedArray) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
