#User function Template for python3

class Solution:
    def productExceptSelf(self, arr):
        #code here
        res=[]
        s=1
        a=1
        if arr.count(0)>1:  #if more than 0 than multiplication will be zero
            res=[0]*len(arr)
            return res
        for i in arr:
            s*=i
            if i != 0:  #storing if one number is 0
                a*=i
        for i in arr:
            #print(s)
            if s == 0 and i == 0: 
                    res.append(a)
            elif s==0 and i!=0:
                res.append(0)
            else:
                res.append(s//i)
        return res




#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())

    for _ in range(t):

        arr = [int(x) for x in input().split()]

        ans = Solution().productExceptSelf(arr)
        print(*ans)
        print("~")

# } Driver Code Ends