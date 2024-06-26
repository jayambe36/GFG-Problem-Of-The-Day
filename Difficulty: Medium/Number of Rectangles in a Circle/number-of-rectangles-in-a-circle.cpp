//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int rectanglesInCircle(int r) {
        // code here
        int cnt = 0;
        for(int i = 1; i <= 2*r; i++) {
            int lo = 1, hi = 2*r;
            int ans = 0;
            while( lo <= hi) {
                int mid = (lo + hi) / 2;
                if( mid*mid + i * i <= 4*r*r) {
                    ans = mid;
                    lo = mid + 1;
                } 
                else hi = mid - 1;
            }
            cnt += ans;
        }
        return cnt;
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
        int ans = ob.rectanglesInCircle(n);
        cout << ans << "\n";
    }
}
// } Driver Code Ends