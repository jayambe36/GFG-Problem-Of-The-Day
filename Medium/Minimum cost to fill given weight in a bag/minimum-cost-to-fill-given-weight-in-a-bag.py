
from typing import List



class Solution:
    def mincost(self, cost, ind, w, dp):
        if(w==0):
            return 0
        if(ind<0):
            return 2**32
        if(cost[ind]==-1):
            return 2**32
        
        if(dp[ind][w]!=-1):
            return dp[ind][w]
        notpick = self.mincost(cost, ind-1, w, dp)
        pick = 2**32
        if(ind+1<=w):
            pick = self.mincost(cost, ind, w-ind-1, dp) + cost[ind]
        dp[ind][w] = min(pick,notpick)
        return dp[ind][w]
    
    def minimumCost(self, n : int, w : int, cost : List[int]) -> int:
        dp = [[-1 for i in range(w+1)] for i in range(n)]
        self.mincost(cost, n-1, w, dp)
        return dp[-1][-1]




#{ 
 # Driver Code Starts
class IntArray:

    def __init__(self) -> None:
        pass

    def Input(self, n):
        arr = [int(i) for i in input().strip().split()]  #array input
        return arr

    def Print(self, arr):
        for i in arr:
            print(i, end=" ")
        print()


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):

        n = int(input())

        w = int(input())

        cost = IntArray().Input(n)

        obj = Solution()
        res = obj.minimumCost(n, w, cost)

        print(res)

# } Driver Code Ends