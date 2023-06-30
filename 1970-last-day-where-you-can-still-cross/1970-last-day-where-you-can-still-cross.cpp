class Solution {
public:
    bool dfs(vector<vector<int>>& grid, int i, int j){
        
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==1)
            return false;
        
        grid[i][j] = 1;
        
        if(i == grid.size()-1)
            return true;
        
        return  dfs(grid, i-1, j) ||
                dfs(grid, i, j-1) ||
                dfs(grid, i+1, j) ||
                dfs(grid, i, j+1) ;
        
    }
    
    bool canCross(vector<vector<int>>& cells, int mid, int row, int col){
        
        vector<vector<int>> grid(row, vector<int>(col, 0));
        
        for(int i=0; i<=mid; i++){
            int x = cells[i][0]-1;
            int y = cells[i][1]-1; // 0 based indexing
            
            grid[x][y] = 1;
        }    
        
        for(int j=0; j<col; j++){
            
            if(grid[0][j] == 0 && dfs(grid, 0, j)){
                return true;
            }
        }
        
        return false;
    }
    
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        
        int l=0;
        int r=cells.size()-1;
        
        int lastDay=0;
        
        while(l <= r){
            
            int mid = l + (r-l)/2;
            
            if(canCross(cells, mid, row, col)){
                lastDay = mid + 1;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        
        return lastDay;
    }
};