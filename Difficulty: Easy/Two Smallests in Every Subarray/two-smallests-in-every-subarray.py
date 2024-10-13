class Solution:
    def pairWithMaxSum(self, arr):
        #code here
        if(len(arr) == 1):
            return -1
        elif(len(arr) == 2):
            a = arr[0] + arr[1]
            return a
        l = []
        for i in range(0,len(arr)-1):
            a = arr[i]+arr[i+1]
            l.append(a)
        return max(l)


#{ 
 # Driver Code Starts
if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().strip().split("\n")

    t = int(data[0])
    lines = data[1:]

    for line in lines:
        s = list(map(int, line.strip().split()))
        solution = Solution()
        res = solution.pairWithMaxSum(s)
        print(res)

# } Driver Code Ends