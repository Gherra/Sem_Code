#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Sorts an array of integers in ascending order using the insertion sort algorithm.
 * 
 * The insertion sort algorithm iteratively takes an element from the unsorted portion
 * of the array and inserts it into its correct position in the sorted portion. This is
 * done by shifting larger elements one position to the right to make space for the current
 * element.
 * 
 * @param arr A reference to the vector of integers to be sorted.
 * 
 * Time Complexity:
 * - Best Case: O(n) (when the array is already sorted)
 * - Worst Case: O(n^2) (when the array is sorted in reverse order)
 * - Average Case: O(n^2)
 * 
 * Space Complexity: O(1) (in-place sorting)
 * 
 * Important Note:
 * - The `prevIndex` variable starts at `i - 1` for each iteration of the `for` loop.
 * - During the while loop, `prevIndex` is decremented (`prevIndex--`), and it can go to `-1`.
 * - This is intentional and safe because the `while` condition (`prevIndex >= 0`) ensures 
 *   that `prevIndex` will never be used to access the array when it is `-1`.
 * - Additionally, `prevIndex` is reset to `i - 1` at the beginning of each iteration of the `for` loop,
 *   so it does not retain its value from previous iterations, which prevents any issues.
 * 
 * This behavior is essential to how the insertion sort algorithm works and ensures correctness.
 */
void insertionSort(vector<int> &arr) {
    // Iterate through the array starting from the second element
    
    for (int i = 1; i < arr.size(); i++) {
        int whileIterCount = 1;
        // Store the current element and determine its correct position in the sorted portion
        int prevIndex = i - 1;
        int currElememt = arr[i];
         for (int k : arr) cout << k << " ";
        
        cout << "\nProcessing element: " << currElememt << ", initial prevIndex: " << prevIndex << endl;

        // Shift elements in the sorted portion to make space for the current element
        while (prevIndex >= 0 && currElememt < arr[prevIndex]) {
            cout << "Inside while loop: prevIndex = " << prevIndex 
                 << ", shifting " << arr[prevIndex] << " to position " << prevIndex + 1 << endl;

            arr[prevIndex + 1] = arr[prevIndex];
            prevIndex--; // Move one step back in the sorted portion
            cout << "After iteration " << whileIterCount++ << " of while loop" << endl;
            for (int k : arr) cout << k << " ";
            cout << endl;
        }

        // Insert the current element at its correct position
        arr[prevIndex + 1] = currElememt;

        // Debugging output after placement
        cout << "Placed " << currElememt << " at position " << prevIndex + 1 << ", current array state: ";
        for (int k : arr) cout << k << " ";
        cout << endl << endl;
    }
}


int main(){
    vector<int> arr = {5, 4, 3, 2, 1};
    insertionSort(arr);
    for(int i : arr){
        cout << i << " ";
    }
    cout << endl;
    return 0;

}

