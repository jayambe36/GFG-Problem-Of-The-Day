//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int isDigitSumPalindrome(int N) {
        // code here
        int x =N;
        int sum = 0;
        int ans = 0;
        while(x>0)
        {
            sum = sum +(x%10);
            x=x/10;
        }
        int y = sum;
        while(y>0)
        {
            ans = ans*10 + (y%10);
            y = y/10;
        }
        if(ans == sum){
            return 1;
        }
        else
        {
            return 0;
        }

    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.isDigitSumPalindrome(N) << "\n";
    }
}

// } Driver Code Ends