class Solution:
    def nearest(self, grid):
        from collections import deque
        m, n = len(grid), len(grid[0])
        max_dist = m + n
        dists = [[max_dist] * n for _ in range(m)]
        q = deque()
        for x in range(m):
            for y in range(n):
                if grid[x][y] == 1:
                    dists[x][y] = 0
                    q.append((x, y))
        
        def neighbors(x, y):
            if x > 0:
                yield (x - 1, y)
            if x < m - 1:
                yield (x + 1, y)
            if y > 0:
                yield (x, y - 1)
            if y < n - 1:
                yield (x, y + 1)
        
        dist = 1
        while q:
            for _ in range(len(q)):
                x, y = q.popleft()
                for nx, ny in neighbors(x, y):
                    if dists[nx][ny] > dist:
                        dists[nx][ny] = dist
                        q.append((nx, ny))
            dist += 1
        return dists