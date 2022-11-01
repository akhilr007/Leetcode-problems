class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        
        int ROWS = grid.size(), COLS = grid[0].size();
        
        vector<int> result(COLS, -1);
        
        for(int c=0; c<COLS; c++){
            
            int x=0, y=c;
            while(true){
                
                if(x >= ROWS){
                    
                    if(y>=0 && y<COLS) result[c] = y;
                    break;
                }
                else{
                    if(y+1<COLS && grid[x][y] == 1 && grid[x][y+1] == 1){
                        x++;
                        y++;
                    }
                    else if(y-1>=0 && grid[x][y] == -1 && grid[x][y-1] == -1){
                        x++;
                        y--;
                    }
                    else break;
                }
            }
        }
        
        return result;
    }
};