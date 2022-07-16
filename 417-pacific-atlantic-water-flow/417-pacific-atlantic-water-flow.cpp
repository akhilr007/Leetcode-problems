class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& heights, int prevHeight, vector<vector<bool>>& vis){
        
        if(r<0 || c<0 || r>=heights.size() || c>=heights[0].size() || vis[r][c] == true || heights[r][c] < prevHeight){
            return;
        }
        
        vis[r][c] = true;
        dfs(r-1, c, heights, heights[r][c], vis);
        dfs(r, c-1, heights, heights[r][c], vis);
        dfs(r+1, c, heights, heights[r][c], vis);
        dfs(r, c+1, heights, heights[r][c], vis);
        
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<bool>> pac(n, vector<bool>(m, false));
        vector<vector<bool>> atl(n, vector<bool>(m, false));
        
        for(int r=0; r<n; r++){
            dfs(r, 0, heights, heights[r][0], pac);
            dfs(r, m-1, heights, heights[r][m-1], atl);
        }
        
        for(int c=0; c<m; c++){
            dfs(0, c, heights, heights[0][c], pac);
            dfs(n-1, c, heights, heights[n-1][c], atl);
        }
        
        vector<vector<int>> res;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(pac[i][j] && atl[i][j]){
                    vector<int> v = {i, j};
                    res.push_back(v);
                }
            }
        }
        
        return res;
    }
};