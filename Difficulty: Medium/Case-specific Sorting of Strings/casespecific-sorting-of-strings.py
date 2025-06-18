class Solution:
    def caseSort(self, s):
        # Separate uppercase and lowercase characters
        upper = sorted([ch for ch in s if ch.isupper()])
        lower = sorted([ch for ch in s if ch.islower()])
        
        result = []
        u = l = 0  # pointers to traverse sorted upper and lower lists

        for ch in s:
            if ch.isupper():
                result.append(upper[u])
                u += 1
            else:
                result.append(lower[l])
                l += 1

        return ''.join(result)
