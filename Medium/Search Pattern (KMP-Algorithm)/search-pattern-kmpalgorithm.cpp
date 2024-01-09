//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            //code here
            vector<int> ans;
            for(int i=0 ; i<txt.size() ; i++){
                int c = i;
                int j = 0;
                
                while(j<pat.length()){
                    if(txt[i] == pat[j]){
                        i++;
                    } else {
                        i = c;
                        break;
                    }
                    j++;
                }
                
                if(j == pat.size()){
                    ans.push_back(c+1);
                    i = c;
                }
            }
            
            if(ans.size() == 0){
                ans.push_back(-1);
                return ans;
            } else {
                return ans;    
            }
        }
     
};




//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends