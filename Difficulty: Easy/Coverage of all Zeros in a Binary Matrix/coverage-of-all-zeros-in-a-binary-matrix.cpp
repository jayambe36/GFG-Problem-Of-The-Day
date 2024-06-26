//{ Driver Code Starts


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int findCoverage(vector<vector<int>>& matrix) {
        // Code here
        std::vector<int> rowDir = {-1, 1, 0, 0};
        std::vector<int> colDir = {0, 0, -1, 1};
        int coverage=0;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                for(int k=0;k<4;k++)
                {
                    if(matrix[i][j]==0)
                    {
                       int newrow=i+rowDir[k];
                       int newcol=j+colDir[k];
                       if(newrow>=0 && newrow<matrix.size() && newcol >=0 && newcol<matrix[0].size() && matrix[newrow][newcol]==1)
                       coverage++;
                    }
                }
            }
        }
        return coverage;
    }

};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        int ans = obj.findCoverage(matrix);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends