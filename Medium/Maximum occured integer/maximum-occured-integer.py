#User function Template for python3

class Solution:
    #Complete this function
    #Function to find the maximum occurred integer in all ranges.
       def maxOccured(self,n, l, r, maxx):
        # Initialize the array with zeros of size maxx+2 to handle r[i] + 1
        arr = [0] * (maxx + 2)
        
        # Apply the difference array concept
        for i in range(n):
            arr[l[i]] += 1
            if r[i] + 1 <= maxx:
                arr[r[i] + 1] -= 1
        
        # Compute prefix sums and find the maximum occurred integer
        max_occur = 0
        max_value = 0
        current_sum = 0
        
        for i in range(maxx + 1):
            current_sum += arr[i]
            if current_sum > max_value:
                max_value = current_sum
                max_occur = i
        
        return max_occur



#{ 
 # Driver Code Starts
#Initial Template for Python 3

import math

A = [0] * 1000000


def main():

    T = int(input())

    while (T > 0):

        global A
        A = [0] * 1000000

        n = int(input())

        l = [int(x) for x in input().strip().split()]
        r = [int(x) for x in input().strip().split()]

        maxx = max(r)
        ob = Solution()
        print(ob.maxOccured(n, l, r, maxx))

        T -= 1


if __name__ == "__main__":
    main()

# } Driver Code Ends