class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        if(grid[0][0] == 1 or grid[n-1][n-1] == 1) return -1;
        
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 2;
        
        int dir[8][2] = {{-1, 0}, {0, -1}, {-1, -1}, {1, -1}, {1, 0}, {0, 1}, {1, 1}, {-1, 1}};
        
        int level = 0;
        while(!q.empty()){
            
            int size = q.size();
            for(int i=0; i<size; i++){
                
                auto head = q.front(); q.pop();
                
                int row = head.first;
                int col = head.second;
                
                if(row == n-1 && col == n-1){
                    return level + 1;
                }
                
                for(int d=0; d<8; d++){
                    
                    int r = row + dir[d][0];
                    int c = col + dir[d][1];
                    
                    if(r >= 0 && c>=0 && r < n && c < n && grid[r][c] == 0){
                        q.push({r, c});
                        grid[r][c] = 2;
                    }
                }
            }
            level++;
        }
        
        return -1;
    }
};