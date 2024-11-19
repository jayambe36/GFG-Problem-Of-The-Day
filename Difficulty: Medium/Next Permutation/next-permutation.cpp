//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++



class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        // idx1 - first index from array end downwards
        int idx1 = arr.size() -1;
        // idx2 - second index for second and third steps
        int idx2 = idx1;
        // num - check for greater number
        int num = arr[idx1];
        // step 1: find the smaller previous element 
        while(idx1 > 0 && num <= arr[idx1])
        {
            num = arr[idx1];
            idx1--;
        }
        // exlude the case of highest permutation
        if(num > arr[idx1])
        {
            // step 2: find element after the smallest
            while(idx1 < idx2 & arr[idx1] >= arr[idx2])
            {
                idx2--;
            }
            // swap elements, increase first index and reset second index
            swap(arr[idx1], arr[idx2]);
            idx1++;
            idx2 = arr.size() - 1;
        }
        // step 3: reverse rest of the array
        while(idx1 < idx2)
        {
            swap(arr[idx1], arr[idx2]);
            idx1++;
            idx2--;
        }
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int n = arr.size();
        ob.nextPermutation(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends