//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    
    int helper(int idx, string &digits, vector<int> &dp)
    {
      
            
        if(idx == digits.size())
            return 1;
        if(digits[idx] == '0')
            return 0;
        if(dp[idx] != -1)
            return dp[idx];
        int one_pick = 0;
        int two_pick = 0;
        
   
        one_pick = helper(idx+1,digits,dp);
        if( (idx < (digits.size() -  1)) && (digits[idx] == '1' || (digits[idx]  == '2' && digits[idx+1] <= '6' ) ))
            two_pick = helper(idx+2,digits,dp);
        return dp[idx] = one_pick + two_pick;
    }
    int countWays(string &digits) {
        // Code here
        if(digits.size() == 0)
            return 0;
        vector<int> dp(digits.size() , -1);
        return helper(0,digits, dp);
    }


};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string digits;
        getline(cin, digits);
        Solution obj;
        int ans = obj.countWays(digits);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends