// time complexity -> O(n*m) + O(n*m), space complexity -> O(1)
class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid){

        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j] == 0 || grid[i][j] == 2){
            return;
        }

        grid[i][j] = 2;

        dfs(i-1, j, grid);
        dfs(i, j-1, grid);
        dfs(i+1, j, grid);
        dfs(i, j+1, grid);
    }

    int numEnclaves(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1 && (i==0 || j == 0 || i==n-1 || j== m-1)){
                    dfs(i, j, grid);
                }
            }
        }

        int numberOfEnclaves=0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1) numberOfEnclaves++;
            }
        }

        return numberOfEnclaves;
    }
};