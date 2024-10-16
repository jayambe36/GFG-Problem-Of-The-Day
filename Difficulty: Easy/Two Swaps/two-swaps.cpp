//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    bool checkSorted(vector<int> &arr) {
        int n = arr.size();
        int displace = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] != i+1) displace++;
            if (arr[arr[i]-1] == i+1) cnt++;
            if (displace > 4) return false;
        }
        if (displace == 3 || displace == 0 || (displace == cnt && cnt == 4)) return true;
        return false;
    }


};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        vector<int> arr;
        while (ss >> num)
            arr.push_back(num);

        Solution ob;
        bool ans = ob.checkSorted(arr);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
}

// } Driver Code Ends