class Solution {
public:
    void travel(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& visited){
        
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || visited[i][j] == true || grid[i][j] == '0'){
            return;
        }
        
        //mark
        visited[i][j] = true;
        
        // travel
        // top
        travel(i-1, j, grid, visited);
        // left
        travel(i, j-1, grid, visited);
        // down
        travel(i+1, j, grid, visited);
        // right;
        travel(i, j+1, grid, visited);
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<bool>> visited(n, vector<bool> (m, false));
        int noOfIslands=0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                if(grid[i][j] == '1' && visited[i][j] == false){
                    
                    travel(i, j, grid, visited);
                    noOfIslands++;
                }
            }
        }
        
        return noOfIslands;
        
    }
};