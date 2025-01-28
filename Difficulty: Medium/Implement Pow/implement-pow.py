#{ 
 # Driver Code Starts
#Initial Template for Python 3


# } Driver Code Ends
#User function Temp
        
        
class Solution:
    def helper(self, b, e, cache):
        if e in cache:
            return cache[e]
        if e == 0:
            return 1
        if e == 1:
            return b
        
        half = e // 2
        ans = self.power(b, half)
        
        if (half << 1) != e:
            cache[e] = ans * ans * b
        else:
            cache[e] = ans * ans
        
        return cache[e]
        
    def power(self, b: float, e: int) -> float:
        if e < 0:
            e *= -1
            b = 1 / b
            
        return self.helper(b, e, dict())


#{ 
 # Driver Code Starts.

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        b = float(input())
        e = int(input())
        ob = Solution()
        result = ob.power(b, e)
        print(f"{result:.5f}")
        print("~")
# } Driver Code Ends