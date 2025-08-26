class Solution:
    def countTriangles(self, arr):
        # code here
        arr.sort()
        n=len(arr)-1
        count=0
        for c in range(n,1,-1):
            i,j=0,c-1
            while i<j:
                sum=arr[i]+arr[j]
                if sum>arr[c]:
                    count+=(j-i)
                    j-=1
                else:
                    i+=1
        return count