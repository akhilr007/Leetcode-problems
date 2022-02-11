class Solution {
public:
    
    int findMaxArea(vector<vector<int>>& grid, vector<vector<bool>>& vis, int i, int j){
        
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()) return 0;
        if(grid[i][j] == 0 || vis[i][j] == true) return 0;
        
        vis[i][j] = true;
        
        int maxArea=0;
        // top -> left -> down -> right
        maxArea = 1 + findMaxArea(grid, vis, i-1, j) + findMaxArea(grid, vis, i, j-1) + findMaxArea(grid, vis, i+1, j) + findMaxArea(grid, vis, i, j+1);
        
        return maxArea;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        
        int maxArea=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1 && vis[i][j] == false){
                    maxArea = max(maxArea, findMaxArea(grid, vis, i, j));
                }
            }
        }
        
        return maxArea;
    }
};