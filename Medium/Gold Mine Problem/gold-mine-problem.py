# User function Template for Python3

class Solution:
    def maxGold(self, n, m, M):
        
        # initilization
        dp=[[0]*m for _ in range(n)]
        for i in range(n):
            dp[i][0]=M[i][0]
            
        # recursion scheme
        for j in range(1,m):
            for i in range(n):
                
                if i>0:
                    right_down=dp[i-1][j-1]
                else:
                    right_down=0
                
                if i<n-1:
                    right_up=dp[i+1][j-1]
                else:
                    right_up=0
                
                right=dp[i][j-1]
                dp[i][j]=max(right_down,right,right_up)+M[i][j]
        
        # find the answer: it is the maximum in the last column
        res=0
        for i in range(n):
            res=max(res,dp[i][m-1])
            
        return res

#{ 
 # Driver Code Starts
# Initial Template for Python3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n, m = [int(x) for x in input().split()]
        tarr = [int(x) for x in input().split()]
        M = []
        j = 0
        for i in range (n):
            M.append(tarr[j:j + m])
            j = j+m
        
        ob = Solution()
        print(ob.maxGold(n, m, M))
# } Driver Code Ends