//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends



#include <vector>
#include <iostream>

class Solution {
  public:
    // Function to return a list containing the union of the two arrays.
    std::vector<int> findUnion(std::vector<int> &a, std::vector<int> &b) {
        std::vector<int> unionResult;
        int i = 0, j = 0;
        int n = a.size(), m = b.size();
        
        while (i < n && j < m) {
            // Skip duplicates in array `a`
            while (i > 0 && i < n && a[i] == a[i - 1]) {
                i++;
            }
            // Skip duplicates in array `b`
            while (j > 0 && j < m && b[j] == b[j - 1]) {
                j++;
            }
            
            if (i < n && j < m) {
                if (a[i] < b[j]) {
                    unionResult.push_back(a[i]);
                    i++;
                } else if (b[j] < a[i]) {
                    unionResult.push_back(b[j]);
                    j++;
                } else {
                    // Both are equal
                    unionResult.push_back(a[i]);
                    i++;
                    j++;
                }
            }
        }
        
        // Add remaining elements from `a`
        while (i < n) {
            if (i == 0 || a[i] != a[i - 1]) {
                unionResult.push_back(a[i]);
            }
            i++;
        }
        
        // Add remaining elements from `b`
        while (j < m) {
            if (j == 0 || b[j] != b[j - 1]) {
                unionResult.push_back(b[j]);
            }
            j++;
        }
        
        return unionResult;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a, b;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        // Read second array
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            b.push_back(number);
        }

        Solution ob;
        vector<int> ans = ob.findUnion(a, b);
        for (int i : ans)
            cout << i << ' ';
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends