class Solution:
    def alternateSort(self,arr):
        # Your code goes here
        arr.sort()
        mid = len(arr)//2
        arr_1 = arr[:mid]
        arr_2 = arr[mid :]
        alt = []

        arr_2.sort(reverse=True)
        
        n = min(len(arr_1), len(arr_2))
        m = max(len(arr_1), len(arr_2))
        i=0
        while i<n:
            alt.append(arr_2[i])
            alt.append(arr_1[i])
            i+=1
        if len(arr_1) >= len(arr_2):
            while i<n:
                alt.append(arr_2[i])
                i+=1
        
            while i<m:
                alt.append(arr_1[i])
                i+=1
        else:
            while i<m:
                alt.append(arr_2[i])
                i+=1
        
            while i<n:
                alt.append(arr_1[i])
                i+=1
        
        return alt


#{ 
 # Driver Code Starts
#Initial Template for Python 3
#Position this line where user code will be pasted.
#Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    while t > 0:
        arr = list(map(int, input().split()))
        ob = Solution()
        ans = ob.alternateSort(arr)
        print(*ans)
        print("~")
        t -= 1

# } Driver Code Ends