//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        // code here
        int i= 0;
        int l = 0, s = 0;
        deque<int>ma;
        deque<int>mi;
        for(int j = 0;j<arr.size();j++){
            while(!ma.empty() && arr[ma.back()] <= arr[j]) ma.pop_back();
            while(!mi.empty() && arr[mi.back()] >= arr[j]) mi.pop_back();
            ma.push_back(j);
            mi.push_back(j);
            if(arr[ma.front()]-arr[mi.front()] <= x){
                int len = j-i+1;
                int pre = s-l+1;
                if(pre < len){
                    l = i, s = j;
                }
            }
            while(i < j && arr[ma.front()]-arr[mi.front()] > x){
                if(ma.front() == i) ma.pop_front();
                if(mi.front() == i) mi.pop_front();
                i++;
                if(arr[ma.front()]-arr[mi.front()] <= x){
                   int len = j-i+1;
                   int pre = s-l+1;
                   if(pre < len){
                      l = i, s = j;
                   }
                }
            }
        }
        vector<int>ans;
        for(int k = l;k<=s;k++){
            ans.push_back(arr[k]);
        }
        return ans;

        
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.longestSubarray(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends