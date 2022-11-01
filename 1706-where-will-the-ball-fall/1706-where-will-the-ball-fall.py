class Solution:
    def findBall(self, grid: List[List[int]]) -> List[int]:
        
        ROWS, COLS = len(grid), len(grid[0])
        
        res = [-1]*COLS
        
        for i in range(COLS):
            x, y = 0, i
            while True:
                if x >= ROWS:
                    if y>=0 and y<COLS:
                        res[i] = y
                    break
                else:
                    if y+1<COLS and grid[x][y]==1 and grid[x][y+1]==1:
                        x += 1
                        y += 1
                    elif y-1>=0 and grid[x][y]==-1 and grid[x][y-1]==-1:
                        x += 1
                        y -= 1
                    else:
                        break
        return res
    