class Solution {
public:
    bool dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& visited, int n, int m){
        
        if(i >= n || i<0 || j<0 || j>=m){
            return false;
        }
        
        if(grid[i][j] == 1 or visited[i][j] == 1)
            return true;
        
        visited[i][j] = 1 ;
        
        bool top = dfs(i-1, j, grid, visited, n, m);
        bool left = dfs(i, j-1, grid, visited, n, m);
        bool down = dfs(i+1, j, grid, visited, n, m);
        bool right = dfs(i, j+1, grid, visited, n, m);
        
        return top && left && down && right;
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> visited(n, vector<int> (m, 0));
        int islands = 0;
        
        //border pe water locked island nai ho sakta hai
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                if(grid[i][j] == 0 && visited[i][j] == 0){
                    
                    islands += dfs(i, j, grid, visited, n, m);
                }
            }
        }
        
        return islands;
    }
};