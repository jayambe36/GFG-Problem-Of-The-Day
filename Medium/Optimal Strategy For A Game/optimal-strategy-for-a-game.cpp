//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    long long dp[1001][1001];
    long long helper(int* arr,int i,int j){
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        
        // we have 2 option either take from front or last and opponent also has 2 option
        
        // let say we pick from front, the opponent will try to make our total min
        // opponent picked it from first 
        long long ans1=helper(arr,i+1,j-1)+arr[i];
        // opponent picked from last
        if(i+1<=j)ans1=min(ans1,helper(arr,i+2,j)+arr[i]);
        
        // let say we pick from last , the opponent will try to make our total min
        long long ans2=helper(arr,i+1,j-1)+arr[j];
        if(j-1>=i)ans2=min(ans2,helper(arr,i,j-2)+arr[j]);
        
        // max ans out of both
        return dp[i][j]=max(ans1,ans2);
    }
    long long maximumAmount(int n, int arr[]){
        memset(dp,-1,sizeof(dp));
        return helper(arr,0,n-1);
    }
};


//{ Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(n,a)<<endl;
	}
	return 0;
}
// } Driver Code Ends