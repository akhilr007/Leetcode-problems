class Solution {
public:
    int calculate(vector<vector<int>>& grid, queue<pair<int, int>>& q, int n, int m){
        
        int freshOranges = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1) freshOranges++;
                else if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }
        
        return freshOranges;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int, int>> q;
        int freshOranges = calculate(grid, q, n, m);
        
        if(freshOranges == 0) return 0;
        
        int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        int levels = -1;
        
        while(!q.empty()){
            levels++;
            int size = q.size();
            
            for(int i=0; i<size; i++){
                
                auto rem = q.front(); q.pop();
            
                int r = rem.first;
                int c = rem.second;

                for(int dr=0; dr<4; dr++){
                    int r_ = r + dir[dr][0];
                    int c_ = c + dir[dr][1];

                    if(r_>=0 && r_<n && c_>=0 && c_<m && grid[r_][c_] == 1){
                        q.push({r_, c_});
                        grid[r_][c_] = 2;
                        freshOranges--;
                    }
                }
            }
        }
        
        if(freshOranges > 0) return -1;
        return levels;
    }
};