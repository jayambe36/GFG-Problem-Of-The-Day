//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends




class Solution {
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
  public:
    int orangesRotting(vector<vector<int>>& mat) {
        int n = mat.size();int m = mat[0].size();
        int ct = 0,C = 0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 2){
                    q.push({i,j});
                    vis[i][j] = 1;
                }
                else if(mat[i][j] == 1){
                    C++;
                }
            }
        }
        int ans = 0;
        while(!q.empty()){
            int siz = q.size();
            bool f = false;
            for(int i=0;i<siz;i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    int X = x+dx[k];
                    int Y = y+dy[k];
                    if(X < 0 || Y < 0 || X >= n || Y >= m || vis[X][Y] ==1 || mat[X][Y]!=1){
                        continue;
                    }
                    else{
                        f = true;
                        q.push({X,Y});
                        vis[X][Y] = true;
                        ct++;
                    }
                }
            }
            if(f){
                ans++;
            }
        }
        // cout << ct << " " << C << endl;
        return (ct != C)?-1:ans;
    }
};



//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(mat);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends