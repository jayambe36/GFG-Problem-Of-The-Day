#User function Template for python3

#User function Template for python3
class Solution:

    def nthRowOfPascalTriangle(self,n):
	    ans=1
        mod=10**9+7
        l2=[]
        l1=[1]
        if(n==1):
            return l1
        elif(n==2):
            return l1+l1
        for i in range(1,n):
            ans=ans*(n-i)
            ans=ans//i
            l2.append(ans%mod)
        return l1+l2


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 

	tc=int(input())
	while tc > 0:
	    n=int(input())
	    ob = Solution()
	    ans=ob.nthRowOfPascalTriangle(n)
	    for x in ans:
	        print(x, end=" ")
	    print()
	    tc=tc-1
# } Driver Code Ends