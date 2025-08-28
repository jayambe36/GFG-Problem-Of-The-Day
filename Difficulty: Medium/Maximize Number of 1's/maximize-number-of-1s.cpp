class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
      int i = 0;
      int j = 0;
      int n = arr.size();
      int maxi = 0;
      int cntZero = 0;
      while(j<n){
          if(arr[j] == 0) cntZero++;
          while(cntZero>k){
              if(arr[i] == 0) cntZero--;
              i++;
          }
          maxi = max(maxi,j-i+1);
          j++;
      }
      return maxi;
    }
};

