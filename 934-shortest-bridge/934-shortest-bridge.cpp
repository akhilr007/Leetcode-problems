class Solution {
private:
    int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
public:
    
    void dfs(int i, int j, vector<vector<int>>& grid, queue<pair<int, int>>& q){
        
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j] != 1){
            return;
        }
        grid[i][j] = 2;
        q.push(make_pair(i, j));
        
        dfs(i-1, j, grid, q);
        dfs(i, j-1, grid, q);
        dfs(i+1, j, grid, q);
        dfs(i, j+1, grid, q);
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        
        int n=grid.size();
        
        bool flag = false;
        queue<pair<int, int>> q;
        
        for(int i=0; i<n && !flag; i++){
            for(int j=0; j<n && !flag; j++){
                if(grid[i][j] == 1){
                    dfs(i, j, grid, q);
                    flag=true;
                }
            }
        }
        
        int level=0;
        
        while(q.size()>0){
            
            int size = q.size();
            
            for(int i=0; i<size; i++){
                
                auto rem = q.front(); q.pop();
                
                int row = rem.first;
                int col = rem.second;
                
                for(int d=0; d<4; d++){
                    int r = row + dir[d][0];
                    int c = col + dir[d][1];
                    
                    if(r>=0 && c>=0 && r<n && c<n){
                        if(grid[r][c] == 0){
                            q.push(make_pair(r, c));
                            grid[r][c] = 2;
                        }
                        else if(grid[r][c] == 1){
                            return level;
                        }
                    }
                }
            }
            level++;
        }
        
        return -1;
    }
};