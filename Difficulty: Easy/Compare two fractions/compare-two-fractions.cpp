//{ Driver Code Starts

#include <iostream>
#include <regex>
using namespace std;


// } Driver Code Ends



class Solution {
  public:
    string compareFrac(string s) {

        // Code here
        string n1,n2,n3,n4;
        int i=0;
        
        while(s[i]!='/'){ //for n1
            n1+=s[i++];
        }
        i++; // for ignoring '/'
        
        while(s[i]!=','){ //for n2
            n2+=s[i++];
        }
        i++; // for ignoring ','
        i++; // for ignoring ' '
        
        while(s[i]!='/'){ //for n3
            n3+=s[i++];
        }
        i++;
        
        while(i<s.size()){ //for n4
            n4+=s[i++];
        }
        
        if(stoi(n1)*1.0/stoi(n2) > stoi(n3)*1.0/stoi(n4)) return n1+"/"+n2;
        else if(stoi(n1)*1.0/stoi(n2) == stoi(n3)*1.0/stoi(n4)) return "equal";
        
        return n3+"/"+n4;
    }
};



//{ Driver Code Starts.

int main() {
    Solution ob;
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {

        string str;
        getline(cin, str);

        cout << ob.compareFrac(str) << endl;
    }
    return 0;
}

// } Driver Code Ends