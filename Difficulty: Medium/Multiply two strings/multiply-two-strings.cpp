//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    /*You are required to complete below function */
    string multiplyStrings(string& s1, string& s2) {
        // Your code here
         bool negative = false;
        if (s1[0] == '-') {
            negative = !negative;  
            s1 = s1.substr(1);  
        }
        if (s2[0] == '-') {
            negative = !negative; 
            s2 = s2.substr(1);  
        }
        
        int len1 = s1.size(), len2 = s2.size();
        
        
        vector<int> result(len1 + len2, 0);
        
        
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        
        
        for (int i = 0; i < len1; i++) {
            for (int j = 0; j < len2; j++) {
                int prod = (s1[i] - '0') * (s2[j] - '0');
                result[i + j] += prod;  
                result[i + j + 1] += result[i + j] / 10;  
                result[i + j] %= 10;  
            }
        }
        
        
        string ans = "";
        bool leadingZero = true;
        for (int i = result.size() - 1; i >= 0; i--) {
            if (result[i] != 0) {
                leadingZero = false;
            }
            if (!leadingZero) {
                ans += (result[i] + '0');
            }
        }
        
        
        if (ans.empty()) {
            return "0";
        }
        
        
        if (negative) {
            ans = "-" + ans;
        }
        
        return ans;
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string a;
        string b;
        cin >> a >> b;
        Solution obj;
        cout << obj.multiplyStrings(a, b) << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends