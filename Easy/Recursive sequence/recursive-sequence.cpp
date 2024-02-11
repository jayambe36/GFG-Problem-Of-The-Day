//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    long long sequence(int n){
        // code here
        long long ans=0;
        
        for(int i=1,M=1e9+7,k=1;i<=n;i++)
        {
          long long pr = 1;
          for(int j=0;j<i;j++,k++)
          {
           pr=(pr*k)%M;
          }
          ans=(ans+pr)%M;
        }
        
        return ans;

    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends