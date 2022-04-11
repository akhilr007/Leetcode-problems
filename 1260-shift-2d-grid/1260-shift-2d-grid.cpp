class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>> res(n, vector<int>(m));
        
        if(k==0) return grid;
        
        for(int K=0; K<k; K++){
            
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    
                    if(j==m-1){
                        res[(i+1)%n][0] = grid[i][j];
                    }
                    else if(i==n-1 && j==m-1){
                        res[0][0] = grid[i][j];
                    }
                    else{
                        res[i][(j+1)%m] = grid[i][j];
                    }
                }
            }
            grid = res;
        }
        
        return res;
    }
};