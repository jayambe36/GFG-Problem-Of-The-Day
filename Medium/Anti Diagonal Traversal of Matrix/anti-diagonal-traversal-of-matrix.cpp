//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> antiDiagonalPattern(vector<vector<int>> matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> ans(n+m-1);
        // negdiag[n-1+r-c]
        for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){
                ans[r+c].push_back(matrix[r][c]);
            }
        }
        vector<int> res;
        for(auto x:ans){
            for(auto y:x){
                res.push_back(y);
            }
        }
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix;
        matrix.resize(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> ans = ob.antiDiagonalPattern(matrix);
        for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends