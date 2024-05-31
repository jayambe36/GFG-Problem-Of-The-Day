
class Solution:
    def oddEven(self, S: str) -> str:
        letters = [0] * 26
        sum = 0
        for c in S:
            letters[ord(c) - 97] += 1
        for i in range(26):
            if i % 2 == 1 and letters[i]!= 0 and letters[i] % 2 == 0:
                sum += 1
            elif i % 2 == 0 and letters[i] % 2 == 1:
                sum += 1
        return "EVEN" if sum % 2 == 0 else "ODD"



#{ 
 # Driver Code Starts
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):

        s = (input())

        obj = Solution()
        res = obj.oddEven(s)

        print(res)

# } Driver Code Ends