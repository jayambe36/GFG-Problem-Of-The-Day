//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int countSubarrays(vector<int>& arr, int k) {
        unordered_map<int, int> prefixSumFreq;
        int current_sum = 0;
        int count = 0;

        // Initialize the hash map with 0 sum frequency as 1
        prefixSumFreq[0] = 1;

        for (int num : arr) {
            current_sum += num;

            // Check if (current_sum - k) exists in the hash map
            if (prefixSumFreq.find(current_sum - k) != prefixSumFreq.end()) {
                count += prefixSumFreq[current_sum - k];
            }

            // Update the frequency of the current_sum in the hash map
            prefixSumFreq[current_sum]++;
        }

        return count;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.countSubarrays(arr, k);
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends