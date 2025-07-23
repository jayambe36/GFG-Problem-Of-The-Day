class Solution {
  public:
    int subarraySum(vector<int>& arr) {
        long long res = 0;
        int n = arr.size();
        for(int i=0;i<n;i++){
            long long freq = 1LL * (i+1) * (n-i);
            res += (1LL * freq * arr[i]);
        }
        return res;
    }
};

