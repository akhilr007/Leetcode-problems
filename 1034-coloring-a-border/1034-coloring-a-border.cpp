class Solution {
public:
    int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    void dfs(vector<vector<int>>& grid, int i, int j, int color){

        grid[i][j] = -color;
        int count = 0;

        for(int d=0; d<4; d++){
            int r = i + dir[d][0];
            int c = j + dir[d][1];

            if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || abs(grid[r][c]) != color){
                continue;
            }

            count++;
            if(grid[r][c] == color){
                dfs(grid, r, c, color);
            }
        }

        if(count == 4){
            grid[i][j] = abs(grid[i][j]);
        }
    }

    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        
        dfs(grid, row, col, grid[row][col]);

        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] < 0){
                    grid[i][j] = color;
                }
            }
        }

        return grid;
    }
};