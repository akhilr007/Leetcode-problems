class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        
        rows = len(grid)
        cols = len(grid[0])
        
        visit = set()
        maxArea = 0
        
        def dfs(i, j, count):
            
            if i<0 or j<0 or i>=rows or j>=cols or grid[i][j] == 0 or (i, j) in visit:
                return
            
            count[0] += 1
            
            visit.add((i, j))
            dfs(i-1, j, count)
            dfs(i, j-1, count)
            dfs(i+1, j, count)
            dfs(i, j+1, count)
        
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 1 and (i, j) not in visit:
                    count = [0]
                    dfs(i, j, count)
                    maxArea = max(maxArea, count[0])
                    
        return maxArea