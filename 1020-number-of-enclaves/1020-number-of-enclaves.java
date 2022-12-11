class Solution {
    private void bfs(Queue<int[]> q, int[][] grid, int[][] vis, int[][] delta){
        
        int N = grid.length;
        int M = grid[0].length;
        
        while(q.size()>0){
            
            int row = q.peek()[0];
            int col = q.peek()[1];
            q.remove();
            
            for(int i=0; i<4; i++){
                int nrow = row + delta[i][0];
                int ncol = col + delta[i][1];
                
                if(nrow >= 0 && ncol >= 0 && nrow < N && ncol < M && grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0){
                    q.add(new int[] {nrow, ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }
    }
    
    private void findEnclavesInGrid(int[][] grid, int[][] vis, int[] cnt){
        
        int N = grid.length;
        int M = grid[0].length;
        
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    cnt[0]++;
                }
            }
        }
    }
    
    public int numEnclaves(int[][] grid) {
        
        int N = grid.length;
        int M = grid[0].length;
        
        int[][] vis = new int[N][M];
        Queue<int[]> q = new LinkedList<>();
        
        // travel for boundary rows
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                
                if(i==0 || j==0 || i==N-1 || j==M-1){
                    if(grid[i][j] == 1){
                        q.add(new int[] {i, j});
                        vis[i][j] = 1;
                    }
                }
            }
        }
        
        
        int[][] delta = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        bfs(q, grid, vis, delta);
        
        int[] cnt = {0};
        findEnclavesInGrid(grid, vis, cnt);
        return cnt[0];
    }
}