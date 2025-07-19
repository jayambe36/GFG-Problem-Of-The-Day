class Solution {
  public:
    int fact(int n){
        if(n<=2){
            return n;
        }
        return n * fact(n-1);
    }
    int vowelCount(string& s) {
         map<char,int>mp;
         for(auto ch:s){
             if(ch == 'a' || ch == 'e' || ch == 'o' || ch == 'i' || ch == 'u'){
                 mp[ch]++;
             }
         }
         int ans = fact(mp.size());
         for(auto pai:mp){
             ans *= pai.second;
         }
         return ans;
    }
};
