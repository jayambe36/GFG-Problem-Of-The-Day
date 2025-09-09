class Solution {
  public:
   int assignHole(vector<int>& mices, vector<int>& holes) {
        // code here
        sort(mices.begin(), mices.end());
        sort(holes.begin(), holes.end());
        
        int n=mices.size();
        int maxi=0;
        
        for(int i=0; i<n; i++){
            maxi=max(maxi, abs(holes[i]-mices[i]));
        }
        
        return maxi;
    }

};