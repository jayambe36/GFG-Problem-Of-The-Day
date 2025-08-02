class Solution:
    def longestSubarray(self, arr, k):
        # Code Here
        # algorithm: turn element to -1, 1 by e <= k or e > k
        # when we have an arr that has only -1, 1; and if 
        # we accumulate the array, the result elemen will be continuous 
        # number (after remove duplicate). because from initial number,
        # we are doing either inc or dec, so, accumulate should be 
        # continuous number, it won't have any gap.
        # for example: [-1, 1, 0, 1, 0, 0, 1, 1, 0, 1] # has 0 or not doesn't matter
        # after  set(accumulate(arr)) => {-1, 0, 1, 2, 3, 4}
       
    
        
        from itertools import accumulate
        arr = [-1 if e <= k else 1 for e in arr]
        acc = accumulate(arr)
        m, running, ans = {}, 0, 0
        for i, e in enumerate(acc):
            if e > 0: # e is already > 0, 0..i is good
                ans = max(ans, i+1) 
            if e not in m:
                m[e] = i
            if e-1 in m:
                ans = max(ans, i-m[e-1])
        return ans

        