//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findWinner(int n, int x, int y)
    {
        // Your code goes here
        int i;
        vector<bool> dp(n+1,false);
        dp[0]=false;
        dp[1]=true;
        for(i=2;i<=n;i++)
        {
            if(i-1 >= 0 && !dp[i-1])
                dp[i]=true;
            if(i-x >= 0 && !dp[i-x])
                dp[i]=true;
            if(i-y >=0 && !dp[i-y])
                dp[i]=true;
        }
        return dp[n] == true ;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        int y;
        scanf("%d", &y);

        Solution obj;
        int res = obj.findWinner(n, x, y);

        cout << res << endl;
    }
}

// } Driver Code Ends