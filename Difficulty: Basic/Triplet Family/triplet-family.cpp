//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  bool findTriplet(vector<int>& arr) {
        // satstar
        int n = arr.size();
        unordered_map<int, int>m;
        
        for(auto &i:arr) m[i]++;
        
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                int sum = arr[i] + arr[j];
                
                if(arr[i]==0 && arr[j] == 0){
                    if(m[0] > 2) return true;
                }
                else if(arr[i] == 0 || arr[j] == 0){
                    if(m[sum] > 1) return true;
                }
                else if(m.count(sum)) return true;
            }
        }
        return false;
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
        Solution obj;
        bool res = obj.findTriplet(arr);
        if (res)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        // cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends