class Solution {
    private int calculateFreshOrangesAndAddRottenOranges(int[][] grid, int[][] vis, Queue<int[]> q){
        
        int cnt=0;
        for(int i=0; i<grid.length; i++){
            for(int j=0; j<grid[0].length; j++){
                
                if(grid[i][j] == 2){
                    q.add(new int[]{i, j});
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
        Queue<int[]> q = new LinkedList<>();
        int freshOranges = calculateFreshOrangesAndAddRottenOranges(grid, vis, q);
        
        if(freshOranges == 0) return 0;
        int[][] delta = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        
        int time=0;
        while(q.size()>0 && freshOranges > 0){
            
            int size = q.size();
            while(size-- > 0){
                
                int row = q.peek()[0];
                int col = q.peek()[1];
                q.remove();
            
                for(int i=0; i<delta.length; i++){
                int nrow = row + delta[i][0];
                int ncol = col + delta[i][1];
                
                    if(nrow >= 0 && ncol >= 0 && nrow < N && ncol < M && grid[nrow][ncol] == 1 && vis[nrow][ncol] != 2){
                        q.add(new int[]{nrow, ncol});
                        vis[nrow][ncol] = 2;
                        freshOranges--;
                    }
                }
            }
            time++;
        }
        
        if(freshOranges == 0) return time;
        return -1;
    }
}