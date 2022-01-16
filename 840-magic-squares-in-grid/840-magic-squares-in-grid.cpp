class Solution {
public:
    
    bool isMagicSquare(vector< vector<int> >& grid, int r, int c){
        
        bool map[10]={false};
        
        for(int i=0; i<=2; i++){
            for(int j=0; j<=2; j++){
                if(grid[r+i][c+j] >= 10){
                    return false;
                }
                
                map[grid[r+i][c+j]]= true;
            }
        }
                    
        for(int i=1; i<=9; i++){
            if(map[i]==false){
                return false;
            }
        }
                    
        if(
            (grid[r][c] + grid[r][c+1] + grid[r][c+2] == 15) &&
            (grid[r+1][c] + grid[r+1][c+1] + grid[r+1][c+2] == 15) &&
            (grid[r+2][c] + grid[r+2][c+1] + grid[r+2][c+2] == 15) &&
            (grid[r][c] + grid[r+1][c] + grid[r+2][c] == 15) &&
            (grid[r][c+1] + grid[r+1][c+1] + grid[r+2][c+1] == 15) &&
            (grid[r][c+2] + grid[r+1][c+2] + grid[r+2][c+2] == 15) &&
            (grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2] == 15) &&
            (grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c] == 15) 
        ){
            return true;
        }
        return false;
    }
                    
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        
        int count=0;
        
        if(grid.size() < 3 || grid[0].size() < 3){
            return false;
        }
        
        for(int i=0; i<grid.size()-2; i++){
            for(int j=0; j<grid[0].size()-2; j++){
                
                // check if the middle element is 5
                if(grid[i+1][j+1] != 5){
                    continue;
                }
                
                bool flag = isMagicSquare(grid, i, j);
                if(flag){
                    count++;
                }
            }
        }
        
        return count;
    }
};