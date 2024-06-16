//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
  bool isprime(int N){
        if(N<=1){
            return false;
        }
        else if(N==2||N==3){
            return true;
        }
        else{
            int cnt=0;
            int k=sqrt(N)+1;
            int i=2;
            while(i<sqrt(N)+1 && i<=k){
                if(N%i==0 || N%k==0){
                    return false;
                }
                i++;
                k--;
            }
            return true;
        }
    }
    vector<int> getPrimes(int n) {
        vector<int>ansH;
        for(int i=0;i<n;i++){
            if(isprime(i)){
                int ans= i;
                int secondans=n-i;
                if(isprime(secondans)){
                    ansH.push_back(ans);
                    ansH.push_back(secondans);
                    return ansH;
                }
            }
        }
        ansH.push_back(-1);
        ansH.push_back(-1);
        return ansH;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        vector<int> res = obj.getPrimes(n);

        Array::print(res);
    }
}

// } Driver Code Ends