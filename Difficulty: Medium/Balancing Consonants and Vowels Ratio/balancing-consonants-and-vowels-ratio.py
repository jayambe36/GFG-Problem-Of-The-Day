class Solution:
    def countBalanced(self, arr):
        # code here
        temp=[]
        for i in arr:
            total=0
            for j in i:
                if j in ('a','e','i','o','u'):
                    total-=1
                else:
                    total+=1
            temp.append(total)
        mp = {}
        mp[0]=1
        curr=0
        ans = 0
        i=0
        while i<len(temp):
            curr+=temp[i]
            i+=1
            ans += mp.get(curr,0)
            mp[curr] = mp.get(curr,0)+1
        return ans