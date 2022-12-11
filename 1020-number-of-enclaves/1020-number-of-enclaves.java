class Solution {
    public int numEnclaves(int[][] grid) {
        
        int N = grid.length;
        int M = grid[0].length;
        
        int[][] vis = new int[N][M];
        Queue<int[]> q = new LinkedList<>();
        
        // travel for boundary rows
        for(int i=0; i<M; i++){
            if(grid[0][i] == 1 && vis[0][i] == 0){
                q.add(new int[] {0, i});
                vis[0][i] = 1;
            }
            
            if(grid[N-1][i] == 1 && vis[N-1][i] == 0){
                q.add(new int[] {N-1, i});
                vis[N-1][i] = 1;
            }
        }
        
        // travel for boundary cols
        for(int i=0; i<N; i++){
            if(grid[i][0] == 1 && vis[i][0] == 0){
                q.add(new int[] {i, 0});
                vis[i][0] = 1;
            }
            
            if(grid[i][M-1] == 1 && vis[i][M-1] == 0){
                q.add(new int[] {i, M-1});
                vis[i][M-1] = 1;
            }
        }
        
        int[][] delta = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
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
        
        int cnt=0;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
}