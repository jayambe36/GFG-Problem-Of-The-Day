class Solution {
  public:
    string maxSubseq(string& s, int k) {
        for(int i=1;i<s.size();i++){
            while(i && s[i]>s[i-1] && k){
                s.erase(i-1,1);
                i--;
                k--;
            } 
        }
        if(k!=0)s.erase(s.size()-k,k);
        return s;
    }
};
