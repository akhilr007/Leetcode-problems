class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>> &visited){
        
        if(r<0 || r>=grid.size() || c<0 || c>=grid[0].size() || grid[r][c] == 0 || visited[r][c] == 1)
            return;
        
        visited[r][c] = 1;
        
        dfs(r-1, c, grid, visited);
        dfs(r, c-1, grid, visited);
        dfs(r+1, c, grid, visited);
        dfs(r, c+1, grid, visited);
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> visited(n, vector<int> (m, 0));
        // dfs on boundary
        // column boundary
        for(int row=0; row<n; row++){
            if(grid[row][0] == 1 and visited[row][0] == 0)
                dfs(row, 0, grid, visited);
            
            if(grid[row][m-1] == 1 and visited[row][m-1] == 0)
                dfs(row, m-1, grid, visited);
        }
        
        // row boundary
        for(int col=0; col<m; col++){
            if(grid[0][col] == 1 and visited[0][col] == 0)
                dfs(0, col, grid, visited);
            
            if(grid[n-1][col] == 1 and visited[n-1][col] == 0)
                dfs(n-1, col, grid, visited);
        }
        
        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                if(grid[i][j] == 1 and visited[i][j] == 0)
                    count++;
            }
        }
        
        return count;
    }
};