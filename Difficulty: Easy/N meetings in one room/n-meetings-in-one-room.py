#User function Template for python3

class Solution:
    
    def maximumMeetings(self,n,start,end):
        # code here
        last = float('-inf')
        meetings = sorted(zip(start, end), key=lambda x: x[1])
        
        cnt = 0
        for s, e in meetings:
            if s > last:
                cnt += 1
                last = e 
        return cnt


#{ 
 # Driver Code Starts
#Initial Template for Python 3
import atexit
import io
import sys

#Contributed by : Nagendra Jha

if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases) :
        n = int(input())
        start = list(map(int,input().strip().split()))
        end = list(map(int,input().strip().split()))
        ob=Solution()
        print(ob.maximumMeetings(n,start,end))
# } Driver Code Ends