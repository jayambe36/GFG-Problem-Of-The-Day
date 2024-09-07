#User function Template for python3

        #code here
class Solution:
    def findNth(self, n):
        result = 0
        multiplier = 1
        # Convert n to a number in base 9
        while n > 0:
            result += (n % 9) * multiplier
            n //= 9
            multiplier *= 10
        return result



#{ 
 # Driver Code Starts
#Initial Template for Python 3

t = int(input())
for i in range(0, t):
    n = int(input())
    obj = Solution()
    s = obj.findNth(n)
    print(s)

# } Driver Code Ends