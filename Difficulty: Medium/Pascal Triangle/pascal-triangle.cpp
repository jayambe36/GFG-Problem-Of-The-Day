//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  public:
    vector<int> nthRowOfPascalTriangle(int n) {
        // code here
        n=n-1;
        vector<int> row;
        long long val = 1;
        for (int k = 0; k <= n; ++k) {
            row.push_back(val);
            val = val * (n - k) / (k + 1);
        }
        return row;
    }
};


//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);

        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends