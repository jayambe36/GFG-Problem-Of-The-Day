//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<bool> visited(n, false);
        vector<int> result;
        stack<int> s;
        
        s.push(0);
        while (!s.empty()) {
            int node = s.top();
            s.pop();
            
            if (!visited[node]) {
                visited[node] = true;
                result.push_back(node);
                
                for (int i = adj[node].size() - 1; i >= 0; --i) {
                    if (!visited[adj[node][i]]) {
                        s.push(adj[node][i]);
                    }
                }
            }
        }
        return result;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V;
        cin >> V;
        cin.ignore();
        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

        for (int i = 0; i < V; i++) {
            string input;
            getline(cin, input);
            int num;
            vector<int> node;
            stringstream ss(input);
            while (ss >> num) {
                node.push_back(num);
            }
            adj[i] = node;
        }

        Solution obj;
        vector<int> ans = obj.dfs(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends