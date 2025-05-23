//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function is to check whether two strings are anagram of each other or not.
    bool areAnagrams(string& s1, string& s2) 
    {
        int arr[26] = {0};
        if(s1.size() != s2.size())
            return false;
        for(int i = 0; i < s1.size(); i++)
        {
            arr[s1[i] - 'a']++;
        }    
        
         for(int i = 0; i < s2.size(); i++)
        {
            arr[s2[i] - 'a']--;
        }  
        for(int i = 0; i < 26; i++)
        {
            if(arr[i] != 0)
                return false;
        }
        return true;
        // Your code here
    }


};

//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {
        string c, d;

        cin >> c >> d;
        Solution obj;
        if (obj.areAnagrams(c, d))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends