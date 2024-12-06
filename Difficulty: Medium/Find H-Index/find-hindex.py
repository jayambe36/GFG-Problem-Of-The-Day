#User function Tem
class Solution:  
    # Function to find hIndex
    def hIndex(self, citations):
        #code here
        c=0
        i=0
        n=len(citations)
        arr.sort()
        arr.reverse()
        for i in range(n):
            if citations[i]>=i+1:
                c+=1
            else:
                break
        return c



#{ 
 # Driver Code Starts
# Initial Template for Python 3

# Main
if __name__ == '__main__':
    t = int(input())
    while t > 0:
        t -= 1
        arr = [int(x) for x in input().strip().split()]

        ob = Solution()
        result = ob.hIndex(arr)

        print(result)
        print("~")

# } Driver Code Ends