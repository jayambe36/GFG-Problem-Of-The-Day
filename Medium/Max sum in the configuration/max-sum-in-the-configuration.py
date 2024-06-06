#User function Template for python3

def max_sum(a,n):
    summ = sum(a)
    sum_pos = 0
    j = n-1
    last = a[j]
    for i in range(n):
        sum_pos += (a[i]*i)
    ans = sum_pos    
    for i in range(1, n):
        sum_pos = sum_pos + summ - (last*n)
        ans = max(sum_pos, ans)
        j -= 1
        last = a[j]
    return ans  



#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        n = int(input())
        arr = list(map(int, input().strip().split()))
        print(max_sum(arr, n))

# } Driver Code Ends