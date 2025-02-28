
class Solution:
    def decodedString(self, s: str) -> str:
        stack = []
        curr_num = 0
        curr_str = ""
        
        for char in s:
            if char.isdigit():
                curr_num = curr_num * 10 + int(char)  # Handle multi-digit numbers
            elif char == '[':
                stack.append((curr_str, curr_num))  # Push current string and num to stack
                curr_str = ""
                curr_num = 0
            elif char == ']':
                last_str, num = stack.pop()
                curr_str = last_str + num * curr_str  # Repeat the string num times
            else:
                curr_str += char  # Build the current string
        
        return curr_str

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        s = input()

        ob = Solution()
        print(ob.decodedString(s))
        print("~")

# } Driver Code Ends