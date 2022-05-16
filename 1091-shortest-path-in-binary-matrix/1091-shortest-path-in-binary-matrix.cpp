class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        if(grid[0][0] != 0) return -1;
        queue<pair<int, int>> q;
        q.push(make_pair(0, 0));
        grid[0][0]=1;
        
        int dir[8][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
        
        while(q.size()>0){
            
            auto curr = q.front(); q.pop();
            int r=curr.first;
            int c=curr.second;
            
            if(r == grid.size()-1 and c == grid.size()-1) return grid[r][c];
            
            for(int d=0; d<8; d++){
                int nr = r + dir[d][0];
                int nc = c + dir[d][1];
                
                if(nr >=0 && nc >= 0 && nr < grid.size() &&nc<grid.size() && grid[nr][nc]==0){
                    q.push(make_pair(nr, nc));
                    grid[nr][nc] = grid[r][c] + 1;
                }
            }
        }
        
        return -1;
    }
};