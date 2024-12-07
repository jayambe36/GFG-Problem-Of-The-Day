

class Solution:
    def inversionCount(self, arr):
        # Helper function for merge sort and inversion counting
        def merge_sort_and_count(arr, temp, left, right):
            if left >= right:
                return 0
            
            # Find the middle point
            mid = (left + right) // 2
            
            # Recursively sort and count inversions in left and right subarrays
            inv_count = merge_sort_and_count(arr, temp, left, mid)
            inv_count += merge_sort_and_count(arr, temp, mid + 1, right)
            
            # Merge the two halves and count cross inversions
            inv_count += merge_and_count(arr, temp, left, mid, right)
            return inv_count
        
        # Merge function that counts cross inversions
        def merge_and_count(arr, temp, left, mid, right):
            i, j, k = left, mid + 1, left
            inv_count = 0
            
            # Merge process with inversion counting
            while i <= mid and j <= right:
                if arr[i] <= arr[j]:
                    temp[k] = arr[i]
                    i += 1
                else:
                    temp[k] = arr[j]
                    inv_count += (mid - i + 1)  # Count inversions
                    j += 1
                k += 1
            
            # Copy remaining elements of left subarray, if any
            while i <= mid:
                temp[k] = arr[i]
                i += 1
                k += 1
            
            # Copy remaining elements of right subarray, if any
            while j <= right:
                temp[k] = arr[j]
                j += 1
                k += 1
            
            # Copy merged elements back to the original array
            arr[left:right + 1] = temp[left:right + 1]
            return inv_count
        
        # Temporary array for merging
        temp = [0] * len(arr)
        return merge_sort_and_count(arr, temp, 0, len(arr) - 1)


#{ 
 # Driver Code Starts
#Initial Template for Python 3

import atexit
import io
import sys

_INPUT_LINES = sys.stdin.read().splitlines()
input = iter(_INPUT_LINES).__next__
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER


@atexit.register
def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())


if __name__ == '__main__':
    t = int(input())
    for tt in range(t):
        a = list(map(int, input().strip().split()))
        obj = Solution()
        print(obj.inversionCount(a))
        print("~")

# } Driver Code Ends