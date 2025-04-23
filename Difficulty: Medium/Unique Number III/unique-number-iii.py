#User function Template for python3

import collections
class Solution:
    def getSingle(self, arr):
        # code here 
        a=collections.Counter(arr)
        return [i for i in a.keys() if a[i]==1][0]



#{ 
 # Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().split()))
        ob = Solution()
        ans = ob.getSingle(arr)
        print(ans)
        print("~")
# } Driver Code Ends