//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
        // utility function that constructs LPS - Longest Proper Prefix
        // use LPS array to find  the matching pattern
        void constructLps(string &pat, vector<int> &lps) {

        // len stores the length of longest prefix which
        // is also a suffix for the previous index
        int len = 0;
        
        // lps[0] is always 0
        lps[0] = 0;
        
        int i = 1;
        while (i < pat.length()) {
            
            // If characters match, increment the size of lps
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            }
            
            // If there is a mismatch
            else {
                if (len != 0) {
                    
                    // Update len to the previous lps value
                    // to avoid reduntant comparisons
                    len = lps[len - 1];
                }
                else
                {
                    // If no matching prefix found, set lps[i] to 0
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
    
    int minChar(string& s) {
        // the approach here is to construct LPS vector of the string
        // then compare the stirng to a reverse copy of itself
        // i - index of the reverse string
        // j - index of the string
        // whenever characters not match, update j according to lps value
        // (meaning use the previous pattern)
        // until reaches end of the string
        // difference between i and j will be the added characters at the left
        
        // length of the string
        int n = s.size();
        // lps vector initialized to 0 and constructed according to s
        vector<int> lps(n, 0);
        constructLps(s, lps);
        // revS - reverse copy of the string
        string revS = string(s.rbegin(), s.rend());
        // i & j - strings indexes
        int i=0, j=0;
        // iterate through revesed copy (revS[i])
        while(i<n)
        {
            // If characters match, move both pointers forward
            if (revS[i] == s[j])
            {
                i++;
                j++;
            }
            // If there is a mismatch
            else
            {
                // Use lps value of previous index
                // to avoid redundant comparisons
                if (j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }
        // return different between the indexes
        return i - j;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.minChar(str);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends