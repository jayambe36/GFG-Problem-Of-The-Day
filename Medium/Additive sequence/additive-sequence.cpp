//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  
   bool cal(string &s,int a ,int b, int c ,int d) {
        // Your code here
        
        int n = s.size();
        while(d<s.size()-1)
        {
            int temp1 = stoi(s.substr(a , b-a+1));
            int temp2  =stoi(s.substr(c ,d-c+1 ));
        
            string temp3 = to_string(temp1 + temp2);
            
            string temp4 = s.substr(d+1 , temp3.size());
            if(temp4!=temp3)
                return 0;
            
            a = c;
            b = d;
            c = d+1;
            d = d+temp4.size();
            if(d >= s.size()-1) return 1;
        }
        return 1;
    }
    bool isAdditiveSequence(string s) {
        // Your code here
        int n = s.size();
            for(int i =0 ; i < min(8 , n) ; i++)
            {
                for(int j = i+1 ; j < min(8 ,n); j++)
                {
                    string temp1 = s.substr(0 ,i+1 );
                    string temp2 = s.substr(i+1 , j-i);
        
                    for(int k = j+1 ; k<n ; k++)
                    {
                        string temp3 = s.substr(j+1 ,k-j);
                        string res = to_string(stoi(temp1) + stoi(temp2));
                        if(res == temp3)
                        {
                            // cout<<"yes "<<0<<" "<<i<<" "<<j<<" "<<k<<" "<<endl;
                                return cal(s,0,i,i+1,j);
                        } 
                    }
                }
            }
            
            return 0;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;

    Solution sol;

    while (t--) {
        string s;
        cin >> s;

        bool result = sol.isAdditiveSequence(s);
        cout << result << endl;
    }

    return 0;
}

// } Driver Code Ends