class Pair{
    int row;
    int col;
    int nearestDistance;
    Pair(int row, int col, int nearestDistance){
        this.row = row;
        this.col = col;
        this.nearestDistance = nearestDistance;
    }
}

class Solution {
    public int[][] updateMatrix(int[][] mat) {
        
        int N = mat.length;
        int M = mat[0].length;
        
        int[][] vis = new int[N][M];
        int[][] dist = new int[N][M];
        Queue<Pair> q = new LinkedList<>();
        
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                
                if(mat[i][j] == 0){
                    q.add(new Pair(i, j, 0));
                    vis[i][j] = 1;
                }
            }
        }
        
        int[][] delta = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        while(q.size()>0){
            int row = q.peek().row;
            int col = q.peek().col;
            int nearestDistance = q.peek().nearestDistance;
            q.remove();
            
            dist[row][col] = nearestDistance;
            for(int i=0; i<4; i++){
                int nrow = row + delta[i][0];
                int ncol = col + delta[i][1];
                
                if(nrow>=0 && nrow<N && ncol>=0 && ncol<M && vis[nrow][ncol]==0){
                    q.add(new Pair(nrow, ncol, nearestDistance+1));
                    vis[nrow][ncol] = 1;
                }
            }
            
        }
        
        return dist;
    }
}