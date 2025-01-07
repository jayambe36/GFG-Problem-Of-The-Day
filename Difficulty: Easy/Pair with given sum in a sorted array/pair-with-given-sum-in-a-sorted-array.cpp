//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countPairs(vector<int> &a, int target) {
        int ans=0;
        for(int i=0;i<a.size();i++){
            int lb=lower_bound(a.begin()+i+1,a.end(),target-a[i])-a.begin();
            int ub=upper_bound(a.begin()+i+1,a.end(),target-a[i])-a.begin();
            ans+=ub-lb;
        }
        return ans;
    }
};



//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int target;
        string input;
        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        cin >> target;
        cin.ignore();
        Solution obj;
        cout << obj.countPairs(arr, target) << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends