class Solution {
public:
    void backtrack(int i, int j, vector<vector<int>>& grid, 
                  int nonObstacle, int& count){
        
        if(grid[i][j] == 2){
            if(nonObstacle == 0){
                count++;
            }
            return;
        }
        
        int val = grid[i][j];
        grid[i][j] = -1;
        nonObstacle--;
        
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        
        for(int d=0; d<4; d++){
            int ni = i + dx[d];
            int nj = j + dy[d];
            
            if(ni >= 0 && ni < grid.size() && nj >= 0 && nj < grid[0].size() && grid[ni][nj] != -1)
            backtrack(ni, nj, grid, nonObstacle, count);
        }
        
        grid[i][j] = val;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        int startX, startY;
        int n = grid.size();
        int m = grid[0].size();
        
        int nonObstacle=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1) {
                    startX = i;
                    startY = j;
                }
                
                if(grid[i][j] == 0 || grid[i][j] == 1) nonObstacle++;
            }
        }
        
        int count=0;
        backtrack(startX, startY, grid, nonObstacle, count);
        return count;
    }
};