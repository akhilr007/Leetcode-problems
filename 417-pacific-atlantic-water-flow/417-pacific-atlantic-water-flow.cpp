class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& heights, vector<vector<bool>>& vis, int prevHeight){
        
        if(r<0 || c<0 || r>=heights.size() || c>=heights[0].size() || heights[r][c] < prevHeight || vis[r][c]==true){
            return;
        }
        
        vis[r][c] = true;
        
        dfs(r-1, c, heights, vis, heights[r][c]);
        dfs(r, c-1, heights, vis, heights[r][c]);
        dfs(r+1, c, heights, vis, heights[r][c]);
        dfs(r, c+1, heights, vis, heights[r][c]);
        
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        vector<vector<int>> res;
        
        int rows = heights.size();
        int cols = heights[0].size();
        
        vector<vector<bool>> pac(rows, vector<bool> (cols, false));
        vector<vector<bool>> atl(rows, vector<bool> (cols, false));
        
        for(int c=0; c<cols; c++){
            dfs(0, c, heights, pac, heights[0][c]);
            dfs(rows-1, c, heights, atl, heights[rows-1][c]);
        }
        
        for(int r=0; r<rows; r++){
            dfs(r, 0, heights, pac, heights[r][0]);
            dfs(r, cols-1, heights, atl, heights[r][cols-1]);
        }
        
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(pac[i][j]==true && atl[i][j]==true){
                    vector<int> v = {i, j};
                    res.push_back(v);
                }
            }
        }
        
        return res;
    }
};