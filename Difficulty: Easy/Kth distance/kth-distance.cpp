//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

#include <vector>
#include <unordered_set>

class Solution {
public:
    bool checkDuplicatesWithinK(std::vector<int>& arr, int k) {
        std::unordered_set<int> seen; // Set to store elements within the window of size k

        for (int i = 0; i < arr.size(); ++i) {
            // If we find a duplicate within the current window size, return true
            if (seen.find(arr[i]) != seen.end()) {
                return true;
            }
            
            // Add the current element to the set
            seen.insert(arr[i]);
            
            // If the window size exceeds k, remove the element that's k indices behind
            if (i >= k) {
                seen.erase(arr[i - k]);
            }
        }

        // If no duplicates within k distance were found, return false
        return false;
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        bool res = obj.checkDuplicatesWithinK(arr, k);
        if (res)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        // cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends