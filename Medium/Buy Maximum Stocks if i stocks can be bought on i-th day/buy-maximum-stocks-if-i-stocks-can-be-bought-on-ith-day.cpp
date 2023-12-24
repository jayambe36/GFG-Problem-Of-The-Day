//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
   int buyMaximumProducts(int n, int k, int price[]){
        vector<pair<int,int>>v;
        for(int i =0; i<n; i++){
            v.push_back(make_pair(price[i], i)); 
        }
        sort(v.begin(), v.end()); 
        
        int ans = 0;
        int count = 0;
        for(int i =0; i<n; i++){
            if(ans<=k){
                for(int j = 0; j <= v[i].second; j++){
                if(ans <= k){
                    ans = ans + v[i].first;
                    count++;
                }
                else break;
                }
            }
            else break;
        }
        return count - 1;
    }


};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends