#User function Template for python3

        # code here
from collections import Counter
class Solution:
    def findSingle(self, n, arr):
        # code here
        d=Counter(arr)
        for i in d:
            if d[i]%2!=0:
                return i
        return 0



#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        N = int(input())
        arr = input().split()
        for itr in range(N):
            arr[itr] = int(arr[itr])
        
        ob = Solution()
        print(ob.findSingle(N, arr))

# } Driver Code Ends