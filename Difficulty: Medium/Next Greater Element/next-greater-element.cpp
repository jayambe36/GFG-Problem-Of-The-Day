//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> nge(n, -1);  // Initialize the result with -1
        stack<int> st;  // Stack to store elements

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {
            // Remove elements smaller than the current element
            while (!st.empty() && st.top() <= arr[i]) {
                st.pop();
            }
            
            // If stack is not empty, assign top element as next greater
            if (!st.empty()) {
                nge[i] = st.top();
            }
            
            // Push current element onto stack
            st.push(arr[i]);
        }

        return nge;
    }
};


//{ Driver Code Starts.

int main() {
    int t; // Number of test cases
    cin >> t;
    cin.ignore(); // Ignore the newline after reading t
    while (t--) {
        vector<int> a;
        string input;

        // Reading the entire input line for the array
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num); // Read the array elements from input string

        Solution obj;
        vector<int> result = obj.nextLargerElement(a);

        // Print the result in the required format
        for (int i = 0; i < result.size(); i++) {
            if (i != 0)
                cout << " ";
            cout << result[i];
        }
        cout << endl;        // Ensure new line after each test case output
        cout << "~" << endl; // Ensure new line after each test case output
    }

    return 0;
}

// } Driver Code Ends