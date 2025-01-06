//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/**
 * This class provides a solution for the problem of finding a pair of elements in an array 
 * that sum up to a value closest to the target.
 */
class Solution {
public:
    /**
     * Finds a pair of elements in the array that sum up to a value closest to the target.
     * 
     * @param a   the array of elements
     * @param target   the target value
     * @return  a vector containing the two elements whose sum is closest to the target
     */
    vector<int> sumClosest(vector<int>& a, int target) {
        vector<int> result;

        // check insufficient length
        if (a.size() < 2) return result;

        sort(a.begin(), a.end());

        int left = 0;
        int right = a.size() - 1;

        int closestDiff = INT_MAX;

        while (left < right) {
            int curSum = a[left] + a[right];
            int curDiff = abs(curSum - target);

            if (curDiff < closestDiff) {
                closestDiff = curDiff;
                result.clear();
                result.push_back(a[left]);
                result.push_back(a[right]);
            }

            if (curSum < target) {
                left++;
            } else {
                right--;
            }
        }

        return result;
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
        int target = stoi(ks);
        Solution ob;
        vector<int> ans = ob.sumClosest(arr, target);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto it : ans) {
                cout << it << " ";
            }
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends