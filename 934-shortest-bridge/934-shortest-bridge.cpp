class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, queue<pair<int, int>>& q){

        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j] != 1){
            return;
        }

        grid[i][j] = 2;
        q.push({i, j});

        dfs(grid, i-1, j, q);
        dfs(grid, i, j-1, q);
        dfs(grid, i+1, j, q);
        dfs(grid, i, j+1, q);

    }

    int shortestBridge(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();

        queue<pair<int, int>> q;
        bool flag = false;

        for(int i=0; i<n && !flag; i++){
            for(int j=0; j<m && !flag; j++){
                if(grid[i][j] == 1){
                    dfs(grid, i, j, q);
                    flag = true;
                }
            }
        }

        int level=-1;
        int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

        while(q.size() > 0){

            int size = q.size();
            level++;

            for(int k=0; k<size; k++){

                auto rem = q.front();
                q.pop();

                int i=rem.first;
                int j=rem.second;

                for(int d=0; d<4; d++){
                    int r = i + dir[d][0];
                    int c = j + dir[d][1];
                    
                    if(r<0 || c<0 || r>=n || c>=m) continue;
                    
                    if(grid[r][c] == 0){
                        q.push({r, c});
                        grid[r][c] = 2;
                    }
                    else if(grid[r][c] == 1){
                        return level;
                    }
                }
            }
        }

        return -1;
    }
};