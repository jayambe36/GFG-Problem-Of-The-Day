class Solution {
    int  isValid(vector<int>&arr,int &k,int key){
        int hour = 0;
        for(auto i :arr){
            if(i <= key){
                hour++;
            }else {
                if(i % key == 0){
                    hour += i/key;
                } else {
                    hour += i/key + 1;
                }
            }
            if(hour > k){
                return -1;
            }
        }
        return 1;
    }
    int BS(vector<int>&arr,int st,int end,int k){
        int ans = 1;
        while( st <= end){
            int mid = (st+end)/2;
            
            int res = isValid(arr,k,mid);
            if(res==1) {
                ans = mid;
                end = mid - 1;
            }
            
            else if(res == -1){
                st = mid + 1;
            }else end = mid - 1;
        }
        return ans;
    }
  public:
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        int n = arr.size();
        int maxi = *max_element(arr.begin(),arr.end()) ;
        if(n == k) return maxi;
        int st = 1;
        int end= maxi;
        return BS(arr,st,end,k);
    }
};

