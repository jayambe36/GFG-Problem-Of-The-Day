class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        // Code here
        int n=arr.size();
        int res=0;
        int i=0,j=0;
        while(true)
        {
            while(i<n && arr[i]!='P')
            {
                i++;
            }
            while(j<n && arr[j]!='T')
            {
                j++;
            }
            if(i==n || j==n)
            {
                break;
            }
            if(abs(j-i)<=k)
            {
                res++;
                i++;
                j++;
            }
            else if(i<j)
            {
               i++; 
            }
            else
            {
                j++;
            }
        }
        return res;
    }


};