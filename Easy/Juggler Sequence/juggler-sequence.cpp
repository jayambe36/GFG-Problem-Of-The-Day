//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
     vector<int> jugglerSequence(int n) {
        // code here
        vector<int>ans;
        ans.push_back(n);
        int prev = n;
        while(prev != 1)
        {
            double curr = prev % 2 == 0 ? pow(1.0*prev,0.5) : pow(1.0*prev,1.5);
            ans.push_back(curr);
            prev = curr;
        }
        return ans;
        
    }

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        vector<int> ans = ob.jugglerSequence(n);
        for (int u : ans)
            cout << u << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends