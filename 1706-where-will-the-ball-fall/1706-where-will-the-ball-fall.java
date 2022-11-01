class Solution {
    public int[] findBall(int[][] grid) {
        
        int ROWS = grid.length;
        int COLS = grid[0].length;
        
        int[] result = new int[COLS];
        Arrays.fill(result, -1);
        
        for(int colNo=0; colNo<COLS; colNo++){
            
            int x=0, y=colNo;
            while(true){
                if(x >= ROWS){
                    if(y>=0 && y<COLS) result[colNo] = y;
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
}