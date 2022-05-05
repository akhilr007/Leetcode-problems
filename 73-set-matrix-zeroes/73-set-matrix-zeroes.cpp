class Solution {
public:
    void setZeroes(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        vector<int> rows(n, 1), cols(m, 1);
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                if(grid[i][j] == 0){
                    rows[i]=0;
                    cols[j]=0;
                }
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(rows[i]==0 or cols[j]==0){
                    grid[i][j]=0;
                }
            }
        }
    }
};