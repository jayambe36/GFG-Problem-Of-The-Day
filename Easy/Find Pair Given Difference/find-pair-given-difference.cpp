//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

#include <vector>
#include <algorithm>

class Solution {
public:
    int findPair(int n, int x, std::vector<int> &arr) {
        // Sort the array to enable the two-pointer technique
        std::sort(arr.begin(), arr.end());
        
        // Initialize two pointers
        int left = 0;
        int right = 1;

        // Traverse the array with two pointers
        while (left < n && right < n) {
            // Calculate the difference between the two elements
            int diff = arr[right] - arr[left];

            // If the difference is equal to x, return 1
            if (diff == x && left != right) {
                return 1;
            }
            // If the difference is less than x, move the right pointer to the right
            else if (diff < x) {
                right++;
            }
            // If the difference is greater than x, move the left pointer to the right
            else {
                left++;
            }

            // Ensure the pointers do not overlap incorrectly
            if (left == right) {
                right++;
            }
        }

        // If no pair is found, return -1
        return -1;
    }
};

// Example usage
/*
int main() {
    Solution sol;
    std::vector<int> arr = {5, 20, 3, 2, 5, 80};
    int result = sol.findPair(6, 78, arr);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
*/


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        vector<int> arr(n);
        Array::input(arr, n);

        Solution obj;
        int res = obj.findPair(n, x, arr);

        cout << res << endl;
    }
}

// } Driver Code Ends