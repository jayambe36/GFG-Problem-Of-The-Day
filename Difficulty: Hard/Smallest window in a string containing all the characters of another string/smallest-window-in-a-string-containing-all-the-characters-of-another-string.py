#User function Template for python3



class Solution:
    def smallestWindow(self, s, p):
        from collections import Counter
        p_count = Counter(p)
        required = len(p_count)
        left, right = 0, 0
        formed = 0
        window_counts = {}
        
        min_length = float('inf')
        min_left = 0
        
        while right < len(s):
            character = s[right]
            window_counts[character] = window_counts.get(character, 0) + 1
            
            if character in p_count and window_counts[character] == p_count[character]:
                formed += 1
            while left <= right and formed == required:
                character = s[left]
                
                if right - left + 1 < min_length:
                    min_length = right - left + 1
                    min_left = left
                
                window_counts[character] -= 1
                if character in p_count and window_counts[character] < p_count[character]:
                    formed -= 1
                
                left += 1
            
            right += 1

        return s[min_left:min_left + min_length] if min_length != float('inf') else "-1"
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

if __name__=='__main__':
    t = int(input())
    for i in range(t):
        s=str(input())
        p=str(input())
        ob = Solution()
        print(ob.smallestWindow(s,p))
# } Driver Code Ends