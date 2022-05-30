class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        
        queue<pair<int, int>> q;
        int n = grid.size();

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    q.push({i, j});
                }
            }
        }
        
        if(q.size() == 0 || q.size() == n*n) return -1;

        int level=-1;
        int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

        while(q.size()>0){
            int size = q.size();
            level++;

            for(int k=0; k<size; k++){
                auto rem = q.front();
                q.pop();

                int i = rem.first;
                int j = rem.second;

                for(int d=0; d<4; d++){
                    int r = i + dir[d][0];
                    int c = j + dir[d][1];

                    if(r >= 0 && c>=0 && r<grid.size() && c<grid[0].size() && grid[r][c] == 0){
                        q.push({r, c});
                        grid[r][c] = 1;
                    }
                }
            }
        }

        return level;
    }
};