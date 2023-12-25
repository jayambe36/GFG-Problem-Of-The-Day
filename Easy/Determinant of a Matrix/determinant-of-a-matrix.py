class Solution:
    def determinantOfMatrix(self,matrix,n):
#        laplace/cofactor expansion
        def hlp(mat,n):
            if n==1:
                return mat[0][0]
            ans=0
            for i in range(n):
                if mat[0][i]==0:
                    continue
                sgn=1 if i%2==0 else -1
                nmat=[[rw[x] for x in range(n) if x!=i] for rw in mat[1:]]
                ans+=sgn*mat[0][i]*hlp(nmat,n-1)
            return ans
        return hlp(matrix,n)



#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        values = list(map(int, input().strip().split()))
        k = 0
        matrix =[]
        for i in range(n):
            row=[]
            for j in range(n):
                row.append(values[k])
                k+=1
            matrix.append(row)
        obj = Solution()
        print(obj.determinantOfMatrix(matrix,n))
# } Driver Code Ends