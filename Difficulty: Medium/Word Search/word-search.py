
class Solution:
    def isWordExist(self, mat, word):
        def dfs(x=0,y=0,i=len(word)-1):
            nonlocal mat,word,hth,wth
            if i<0:
                return True
            if mat[y][x]!=word[i]:
                return False
            for dx,dy in [(0,1),(0,-1),(1,0),(-1,0)]:
                nx=x+dx
                ny=y+dy
                if not 0<=nx<wth or not 0<=ny<hth:
                    continue
                tmp=mat[y][x]
                mat[y][x]=''
                if dfs(nx,ny,i-1):
                    return True
                mat[y][x]=tmp
            return False
        hth=len(mat)
        wth=len(mat[0])
        for y in range(hth):
            for x in range(wth):
                if dfs(x,y):
                    return True
        return False


#{ 
 # Driver Code Starts
if __name__ == '__main__':
    T = int(input())
    for tt in range(T):
        n = int(input())
        m = int(input())
        mat = []
        for i in range(n):
            a = list(input().strip().split())
            b = []
            for j in range(m):
                b.append(a[j][0])
            mat.append(b)
        word = input().strip()
        obj = Solution()
        ans = obj.isWordExist(mat, word)
        if ans:
            print("true")
        else:
            print("false")
        print("~")

# } Driver Code Ends