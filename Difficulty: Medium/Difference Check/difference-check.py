class Solution:
    def toSec(self, string):
        # Converts HH:MM:SS to total seconds
        h, m, s = map(int, string.split(":"))
        return h * 3600 + m * 60 + s

    def minDifference(self, arr):
        # Total number of seconds in a day
        maxTime = 86400
        time = [False] * (maxTime + 1)

        for item in arr:
            second = self.toSec(item)
            if time[second]:
                return 0  # duplicate time found
            time[second] = True

        first = prev = None
        ans = float('inf')

        for i in range(maxTime):
            if time[i]:
                if prev is not None:
                    ans = min(ans, i - prev)
                prev = i
                if first is None:
                    first = i

        # Compare last and first to cover circular difference
        return min(ans, maxTime - prev + first)

