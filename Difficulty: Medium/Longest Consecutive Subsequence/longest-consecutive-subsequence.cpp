//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    // Function to return the length of the longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Using an unordered set for O(1) average-time complexity lookups
        unordered_set<int> numSet(arr.begin(), arr.end());
        int maxLength = 0;

        // Iterate through each number in the array
        for (int num : arr) {
            // Check if the current number is the start of a sequence
            if (numSet.find(num - 1) == numSet.end()) {
                int currentNum = num;
                int currentLength = 1;

                // Count consecutive numbers
                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum++;
                    currentLength++;
                }

                // Update the maximum length
                maxLength = max(maxLength, currentLength);
            }
        }

        return maxLength;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.longestConsecutive(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends