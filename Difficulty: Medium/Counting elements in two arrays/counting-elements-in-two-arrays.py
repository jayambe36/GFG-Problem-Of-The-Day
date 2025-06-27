from bisect import bisect_right

class Solution:
    def countLessEq(self, a, b):
        b.sort()  # Sort b[] once
        result = []
        
        for x in a:
            # Find how many elements in b[] are ≤ x
            count = bisect_right(b, x)
            result.append(count)
        
        return result
