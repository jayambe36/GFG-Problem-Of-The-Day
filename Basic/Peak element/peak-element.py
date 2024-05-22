# your task is to complete this function
# function should return index to the any valid peak element


class Solution:   
    def peakElement(self,arr, n):
        left = 0
        right = n-1
        while left<=right:
            middle = (left+right)//2
            # If there is a peak element, return its index.
            if (middle==0 or arr[middle]>=arr[middle-1]) and (middle==n-1 or arr[middle]>=arr[middle+1]):
                    return middle
            # If middle-1 is greater than middle, the peak is on the left side.
            elif middle>0 and arr[middle-1]>arr[middle]:
                right=middle-1
            # Otherwise, the peak is on the right side.
            else:
                left=middle+1
        # If there is no peak element, return 0.
        return 0

#{ 
 # Driver Code Starts

if __name__=='__main__':
    t = int(input())
    for i in range(t):
        n = int(input())
        arr = list(map(int, input().strip().split()))
        index = Solution().peakElement(arr.copy(), n)
        flag = False
        if index<0 or index>=n:
            flag = False
        else:
            if index == 0 and n==1:
                flag = True
            elif index==0 and arr[index]>=arr[index+1]:
                flag = True
            elif index==n-1 and arr[index]>=arr[index-1]:
                flag = True
            elif arr[index-1] <= arr[index] and arr[index] >= arr[index+1]:
                flag = True
            else:
                flag = False

        if flag:
            print(1)
        else:
            print(0)
# Contributed by: Harshit Sidhwa

# } Driver Code Ends