class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {

        int n=grid.size();
        
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.push(make_tuple(grid[0][0], 0, 0)); // msf -> minimum weight so far, row, col

        vector<vector<bool>> vis(n, vector<bool>(n, false));

        int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

        while(pq.size()>0){
            
            auto [msf, row, col] = pq.top();
            pq.pop();

            if(row == n-1 && col == n-1){
                return msf;
            }
            
            if(vis[row][col] == true){
                continue;
            }

            vis[row][col] = true;

            for(int d=0; d<4; d++){
                int i = row + dir[d][0];
                int j = col + dir[d][1];

                if(i<0 || j<0 || i>=n || j>=n || vis[i][j] == true) continue;
                
                int maxi = max(msf, grid[i][j]);
                pq.push(make_tuple(maxi, i, j));
            } 
        }

        return 0;
    }
};