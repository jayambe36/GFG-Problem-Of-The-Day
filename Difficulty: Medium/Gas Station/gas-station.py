
class Solution:
    def startStation(self, gas, cost):
        arr=[x-y for x,y in zip(gas,cost)]*2
        lth=len(gas)
        l=0
        sm=arr[l]
        r=1
        while l<lth:
            if sm>=0:
                if r-l>=lth:
                    return l
                sm+=arr[r]
            else:
                l=r
                sm=arr[l]
            r+=1
        return -1



#{ 
 # Driver Code Starts
#Initial Template for Python 3
import io
import sys

if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        gas = list(map(int, input().strip().split()))
        cost = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.startStation(gas, cost)
        print(ans)
        print("~")

# } Driver Code Ends