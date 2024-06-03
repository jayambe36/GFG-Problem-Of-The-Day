#User function Templ
class Solution:
    def numberOfConsecutiveOnes (ob,n):
        # code here 
        fuck, this = 0, 1
        
        for p in range(1, n-1):
            fuck, this = this, (fuck + this + pow(2, p, (10**9 + 7)))%(10**9 + 7)
            
        return this



#{ 
 # Driver Code Starts
#Initial Template for Python 3
if __name__ == '__main__':
    t = int(input())
    for _ in range(t):

        N = int(input())

        ob = Solution()
        print(ob.numberOfConsecutiveOnes(N))

# } Driver Code Ends