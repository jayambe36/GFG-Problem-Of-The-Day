//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int DivisibleByEight(string s){
        int n = s.size();
        int num = 0;
        if(n >= 3){
            string str = "";
            str += s[n-3];
            str += s[n-2];
            str += s[n-1];
            num = stoi(str);
        }
        else{
            num = stoi(s);
        }
        if(num == 0 || num%8 == 0) return 1;
        else return -1;
    }
};



//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.DivisibleByEight(S)<<"\n";
    }
}
// } Driver Code Ends