//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
   int find(int k, int arr[], int left, int right){
        int mid = (left + right)/2;
        //base
        if(arr[mid] <= k && k <= arr[mid+1])
            return abs(k-arr[mid]) >= abs(k-arr[mid+1]) ? mid+1 : mid;
        //bin search
        if(k > arr[mid]) 
            return find(k, arr, mid+1, right);
        return find(k, arr, left, mid-1);
    }
    
    int findClosest( int n, int k,int arr[]) 
    {
        return arr[find(k, arr, 0, n-1)];
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(n,k,arr)<<endl;
    }
}

// } Driver Code Ends