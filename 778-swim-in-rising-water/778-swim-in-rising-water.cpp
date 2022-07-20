class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        
        int n = grid.size();
        
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.push(make_tuple(grid[0][0], 0, 0));
        
        vector<vector<bool>> visit(n, vector<bool>(n, false));
        int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        
        int t=0;
        
        while(!pq.empty()){
            
            auto [t, row, col] = pq.top();
            pq.pop();
            
            if(row == n-1 and col == n-1) return t;
            
            if(visit[row][col] == true) continue;
            
            visit[row][col] = true;
            
            for(int dr=0; dr<4; dr++){
                int r = row + dir[dr][0];
                int c = col + dir[dr][1];
                
                if(r<0 || c<0 || r>=n || c>=n || visit[r][c] == true) continue;
                
                int maxi = max(t, grid[r][c]);
                pq.push(make_tuple(maxi, r, c));
            }
        }
        
        return -1;
    }
};