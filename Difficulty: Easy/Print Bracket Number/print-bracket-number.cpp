//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    vector<int> bracketNumbers(string str) {
        int maxi =0;
        stack<pair<char,int>> s;
        vector<int> ans;
        for(int i =0;i< str.size();i++){
            char c =str[i];
            if(c == ')' && s.empty()){
                maxi+=1;
                ans.push_back(maxi);
                s.push({')',maxi});
            }
            else if(c == ')' && !s.empty()){
                if(s.top().first == '('){
                    ans.push_back(s.top().second);
                    s.pop();
                }
            }
            else if(c == '('){
                maxi+=1;
                ans.push_back(maxi);
                s.push({'(',maxi});
            }
        }
        return ans;
    }
};



//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;

        vector<int> ans = ob.bracketNumbers(s);

        for (auto i : ans)
            cout << i << " ";

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends