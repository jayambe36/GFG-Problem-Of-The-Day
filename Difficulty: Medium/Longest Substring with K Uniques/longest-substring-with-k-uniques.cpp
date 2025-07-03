class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int ans=-1;
        int i=0;
        int n=s.length();
        unordered_map<int,int>mp;
        for(int  j =0; j<n;j++){
            mp[s[j]]++;
            if(mp.size()==k)ans=max(ans, j-i+1);
                else if(mp.size()>k){
                    while(mp.size()>k){
                        if(mp[s[i]]>1)mp[s[i]]--;
                        else mp.erase(s[i]);
                        i++;
                    }
                }
            
        }
        return ans;
    }

};