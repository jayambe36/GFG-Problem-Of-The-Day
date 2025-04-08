//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int u, int parent, vector<int> adj[], vector<bool> &vis, vector<int> &tin, vector<int> &low, int &timer, set<int> &ap) {
        vis[u] = true;
        tin[u] = low[u] = timer++;
        int children = 0;

        for (int v : adj[u]) {
            if (v == parent) continue;
            if (!vis[v]) {
                dfs(v, u, adj, vis, tin, low, timer, ap);
                low[u] = min(low[u], low[v]);

                if (parent != -1 && low[v] >= tin[u]) {
                    ap.insert(u);
                }

                children++;
            } else {
                low[u] = min(low[u], tin[v]);
            }
        }

        if (parent == -1 && children > 1) {
            ap.insert(u);
        }
    }

    vector<int> articulationPoints(int V, vector<vector<int>> &edges) {
        vector<int> adj[V];
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> vis(V, false);
        vector<int> tin(V, -1), low(V, -1);
        set<int> ap;
        int timer = 0;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, -1, adj, vis, tin, low, timer, ap);
            }
        }

        if (ap.empty()) return {-1};
        return vector<int>(ap.begin(), ap.end());
    }
};



//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges;
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }
        Solution obj;
        vector<int> ans = obj.articulationPoints(V, edges);
        sort(ans.begin(), ans.end());
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends