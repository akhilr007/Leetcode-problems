class Solution {
public:
    int bfs(vector<vector<int>>& grid, queue<pair<int, pair<int, int>>>& q, int n){
        
        vector<vector<int>> vis(n, vector<int>(n, 0));
        int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        
        int res = 0;
        
        while(!q.empty()){
            
            auto it = q.front();
            q.pop();
            
            int dist = it.first;
            int r = it.second.first;
            int c = it.second.second;
            
            res = max(res, dist);
            
            for(int d=0; d<4; d++){
                
                int nr = r + dir[d][0];
                int nc = c + dir[d][1];
                
                if(nr>=0 && nc>=0 && nr<n && nc< n &&
                   grid[nr][nc] == 0 && vis[nr][nc] == 0){
                    
                    q.push({dist+1, {nr, nc}});
                    vis[nr][nc] = 1;
                }
            }
        
        }
        
        return res;
    }
    
    int maxDistance(vector<vector<int>>& grid) {
        
        int n = grid.size();
        queue<pair<int, pair<int, int>>> q;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++)
                if(grid[i][j] == 1)
                    q.push({0, {i, j}});
                    
        }
        
        if(q.size() == 0 || q.size() == n*n)
            return -1;
        
        return bfs(grid, q, n);
    }
};