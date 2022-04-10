class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        // calculate fresh oranges and add rotten oranges into queue
        queue<pair<int, int>> q;
        
        int fresh=0;
        
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                
                if(grid[i][j] == 2){
                    q.push(make_pair(i, j));
                }
                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        
        if(fresh == 0) return 0;
        
        int level = -1;
        
        int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}}; // top left down right
        
        while(q.size()>0){
            
            int size=q.size();
            level++;
            
            for(int k=0; k<size; k++){
                
                auto rem = q.front(); q.pop();
                
                int r = rem.first;
                int c = rem.second;
                
                for(int i=0; i<4; i++){
                    int rdash = r + dir[i][0];
                    int cdash = c + dir[i][1];
                    
                    if(rdash >= 0 && cdash >=0 && rdash < grid.size() && cdash <grid[0].size() && grid[rdash][cdash] == 1){
                        q.push(make_pair(rdash, cdash));
                        grid[rdash][cdash]=0;
                        fresh--;
                    }
                }
            }
        }
        
        if(fresh == 0){
            return level;
        }
        else{
            return -1;
        }
    }
};