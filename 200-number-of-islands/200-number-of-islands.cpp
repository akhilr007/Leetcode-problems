class Solution {
public:
    void travel(int i, int j, vector<vector<char>>& grid){
        
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '2' || grid[i][j] == '0'){
            return;
        }
        
        //mark
        grid[i][j] = '2';
        
        // travel
        // top
        travel(i-1, j, grid);
        // left
        travel(i, j-1, grid);
        // down
        travel(i+1, j, grid);
        // right;
        travel(i, j+1, grid);
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        //vector<vector<bool>> visited(n, vector<bool> (m, false));
        int noOfIslands=0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                if(grid[i][j] == '1'){
                    
                    travel(i, j, grid);
                    noOfIslands++;
                }
            }
        }
        
        return noOfIslands;
        
    }
};