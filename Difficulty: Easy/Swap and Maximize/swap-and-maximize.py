#User function Template for python3

class Solution:
    def maxSum(self, arr):
        # Sort the array
        arr.sort()
        
        res = 0
        start = 0
        end = len(arr) - 1
        while start < end:
            res += abs(arr[end] - arr[start]) + abs(arr[end] - arr[start + 1])
            start += 1
            end -= 1
        
        res += abs(arr[0] - arr[start])
        return res



#{ 
 # Driver Code Starts
#Initial Template for Python 3


def main():
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().split()))
        ob = Solution()
        ans = ob.maxSum(arr)  # Call maxSum method and store result in ans
        print(ans)  # Print the result
        print("~")


if __name__ == "__main__":
    main()

# } Driver Code Ends