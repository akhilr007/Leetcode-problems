class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        
        queue<pair<int, int>> q;
        int dir[4][2]  {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        
        int count=0;
        
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                
                if(grid[i][j] == 1){
                    
                    q.push({i, j});
                    
                    while(q.size() > 0){
                        
                        auto rem = q.front();
                        q.pop();
                        
                        int r = rem.first;
                        int c = rem.second;
                        
                        for(int d=0; d<4; d++){
                            
                            int row = r + dir[d][0];
                            int col = c + dir[d][1];
                            
                            if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size()){
                                count++;
                            }
                            else if(grid[row][col] == 0){
                                count++;
                            }
                        }
                    }
                }
            }
        }
        
        return count;
    }
};