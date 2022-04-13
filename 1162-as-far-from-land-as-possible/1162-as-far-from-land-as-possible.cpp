class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        
        int n = grid.size();
        
        queue<pair<int, int>> q;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                
                if(grid[i][j] == 1){
                    q.push(make_pair(i, j));
                }
            }
        }
        
        if(q.size() == 0 || q.size() == n*n){
            return -1;
        }
        
        int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        int level=-1;
        
        while(q.size()>0){
            
            level++;
            int size=q.size();
            
            for(int i=0; i<size; i++){
                
                auto rem = q.front(); q.pop();
            
                int r = rem.first;
                int c = rem.second;

                for(int i=0; i<4; i++){
                    int row = r + dir[i][0];
                    int col = c + dir[i][1];

                    if(row >= 0 && col >= 0 && row < n && col < n && grid[row][col] == 0){
                        q.push({row, col});
                        grid[row][col] = 1;
                    }
                }
            }
        }
        
        return level;
    }
};