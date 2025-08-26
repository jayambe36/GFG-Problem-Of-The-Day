class Solution {
  public:
    bool isSubSeq(string& s1, string& s2) {
        // code here
        bool ans=true;
        int p1=0,p2=0;
        int n1=s1.size(),n2=s2.size();
        while(p1<n1&&p2<n2){
            if(s1[p1]==s2[p2]){
                p1++;
            }
            p2++;
        }
        if(p1!=n1){
            ans=false;
        }
        return ans;
    }
};