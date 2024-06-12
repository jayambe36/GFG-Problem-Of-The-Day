#User function Template for python3

class Solution:
    def padovanSequence(self, n):
        if n < 3:
            return 1
        p0, p1, p2 = 1, 1, 1
        MOD = 10**9 + 7
        for i in range(3, n + 1):
            p0, p1, p2 = p1, p2, (p1 + p0) % MOD
        
        return p2 


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        ob = Solution()
        print(ob.padovanSequence(n))

# } Driver Code Ends