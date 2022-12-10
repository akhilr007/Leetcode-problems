class Pair{
    int row;
    int col;
    int time;
    Pair(int row, int col, int time){
        this.row = row;
        this.col = col;
        this.time = time;
    }
}

class Solution {
    private int calculateFreshOrangesAndAddRottenOranges(int[][] grid, int[][] vis, Queue<Pair> q){
        
        int cnt=0;
        for(int i=0; i<grid.length; i++){
            for(int j=0; j<grid[0].length; j++){
                
                if(grid[i][j] == 2){
                    q.add(new Pair(i, j, 0));
                    vis[i][j] = 2;
                }
                else{
                    vis[i][j] = 0;
                }
                
                if(grid[i][j] == 1) cnt++;
            }
        }
        
        return cnt;
    }
    
    public int orangesRotting(int[][] grid) {
        
        int N = grid.length;
        int M = grid[0].length;
        
        int[][] vis = new int[N][M];
        Queue<Pair> q = new LinkedList<>();
        int freshOranges = calculateFreshOrangesAndAddRottenOranges(grid, vis, q);
        
        if(freshOranges == 0) return 0;
        int[][] delta = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        
        int time=0;
        while(q.size()>0){
            
            int row = q.peek().row;
            int col = q.peek().col;
            int tm = q.peek().time;
            time = Math.max(time, tm);
            q.remove();

            for(int i=0; i<delta.length; i++){
            int nrow = row + delta[i][0];
            int ncol = col + delta[i][1];

                if(nrow >= 0 && ncol >= 0 && nrow < N && ncol < M && grid[nrow][ncol] == 1 && vis[nrow][ncol] != 2){
                    q.add(new Pair(nrow, ncol, tm + 1));
                    vis[nrow][ncol] = 2;
                    freshOranges--;
                }
            }
        }
        
        if(freshOranges == 0) return time;
        return -1;
    }
}