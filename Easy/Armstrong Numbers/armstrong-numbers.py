#User function Template for python3

class Solution:
    def armstrongNumber (self, n):
        # code here 
        if n == pow(int(str(n)[0]), 3) + pow(int(str(n)[1]), 3) + pow(int(str(n)[2]), 3):
            return 'Yes'

        return 'No'



#{ 
 # Driver Code Starts
#Initial Template for Python 3
if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        n = input()
        n=int(n)
        ob = Solution()
        print(ob.armstrongNumber(n))
# } Driver Code Ends