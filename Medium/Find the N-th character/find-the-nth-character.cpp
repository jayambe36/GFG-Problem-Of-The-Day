//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    char nthCharacter(string s, int r, int n) {
             string temp="";
        for(int i=0;i<r;i++)
        {
            int j=0;
            while(temp.length()<=n)
            {
                if(s[j]=='0')
                temp+="01";
                else
                temp+="10";
                j++;
            }
            s=temp;
            temp="";
        }
        return s[n];
    }

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, N;
        string S;
        cin >> S >> R >> N;
        Solution ob;
        cout << ob.nthCharacter(S, R, N) << endl;
    }
    return 0;
}
// } Driver Code Ends