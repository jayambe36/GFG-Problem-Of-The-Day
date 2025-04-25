//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    
    
    int majorityElement(vector<int>& arr) {
       int n=arr.size();
       sort(arr.begin(),arr.end());
       int t=arr[n/2];
        int c=0;
       for(int i=0;i<n;i++)if(arr[i]==t)c++;
       if(c>n/2)return t;
       else return -1;
    }

};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.majorityElement(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends