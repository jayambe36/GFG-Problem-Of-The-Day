//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    int digitSum(int n){
        int sum=0;
        while(n){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
    bool isPrime(int n){
        if(n<=1){
            return false;
        }
        for(int i=2;i<=sqrt(n);i++){
            if(!(n%i)){
                return false;
            }
        }
        return true;
    }
    int smithNum(int n) {
        // code here

//we need only composite no.
        if(isPrime(n)){
            return false;
        }
        int sumOfDigit=digitSum(n);
        int primeSum=0;
        for(int i=2;i<=n;i++){
            if(isPrime(i)){
                int temp=0;
                while(!(n%i)){

//we want sum of digit of prime factor
                    temp+=digitSum(i);
                    n/=i;
                }
                primeSum+=temp;
            }
        }
        //cout<<primeSum<<endl;
        //cout<<sumOfDigit<<endl;
        return primeSum==sumOfDigit;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.smithNum(n) << endl;
    }
    return 0;
}
// } Driver Code Ends