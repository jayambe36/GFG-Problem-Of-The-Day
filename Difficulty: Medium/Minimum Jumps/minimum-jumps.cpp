//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array



class Solution {
  public:
    int minJumps(vector<int>& arr) {
        int curr_reach = 0;
        int max_reach = 0;
        int jump = 0;
        
        for(int i=0;i<arr.size();i++){
            max_reach = max(max_reach,arr[i]+i);    //Every Time update the max where we can Reach
            
            if(i == curr_reach){       //If once reach the Destination,give Curr_reach a new Target & Increase Jump
                curr_reach = max_reach;
                jump++;
                
                if(curr_reach >= arr.size()-1){    //If curr_reach getting out_of_bound then Simply return Jump
                    return jump;
                }
            }
        }
        return -1;    //At last if Jump is not returned then return -1
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends