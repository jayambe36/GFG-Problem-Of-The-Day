#User function Template for python3

from bisect import bisect_right
class Solution:
    def countElements(self, a, b, n, query, q):
        # code here
        res=[]
        d={}
        b.sort()
        for i in range(n):
            idx=bisect_right(b,a[i])
            if idx>=n:
                d[i]=n
            else:
                d[i]=idx
        for i in query:
            res.append(d[i])
        return res


#{ 
 # Driver Code Starts
#Initial Template for Python 3

t = int(input())
for _ in range(0, t):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    q = int(input())
    query = []
    ob = Solution()
    for i in range(q):
        query.append(int(input()))
    ans = ob.countElements(a, b, n, query, q)
    for i in range(q):
        print(ans[i])

# } Driver Code Ends