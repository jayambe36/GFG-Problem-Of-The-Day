//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to reverse words in a given string.
    
    
     string reverseWords(string str) {
        int n=str.size();
        vector<string>ans;
        string temp="";
        for(int i=0;i<n;i++){
            if(str[i]=='.'){
                ans.push_back(temp);
                temp="";
                continue;
            }
            temp+=str[i];
        }
        ans.push_back(temp);
        string res="";
        int m=ans.size();
        
        for(int i=m-1;i>=0;i--){
            res+=ans[i];
            res+='.';
        }
       
        return res.substr(0,res.size()-1);
    }


};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends