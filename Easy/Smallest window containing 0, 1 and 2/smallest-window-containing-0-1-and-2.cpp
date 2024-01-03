//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int smallestSubstring(string S) {
        int n = S.size();
        int i = 0, j = 0;
        int z = 0, o = 0, t = 0;
        int ans = INT_MAX;

        while (i < n) {
            if (S[i] == '0')
                z++;
            else if (S[i] == '1')
                o++;
            else
                t++;

            while (j <= i && (z > 1 || o > 1 || t > 1)) {
                bool flag = false;
                if (S[j] == '0' && z > 1) {
                    z--;
                    flag = true;
                } else if (S[j] == '1' && o > 1) {
                    o--;
                    flag = true;
                } else if (S[j] == '2' && t > 1) {
                    t--;
                    flag = true;
                }
                if (flag)
                    j++;
                else
                    break;
            }

            if (o >= 1 && t >= 1 && z >= 1) {
                ans = min(ans, i - j + 1);
            }

            i++;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends