class Solution {
  public:
    int maxSum(vector<int> &arr) {
        int right = 0;
        int left = 1;
        int  ans = INT_MIN;
        while(left < arr.size()){
            
            int temp = arr[right++] + arr[left++];
            
            ans = max(ans,temp);
        }
        
        return ans;
    }


};