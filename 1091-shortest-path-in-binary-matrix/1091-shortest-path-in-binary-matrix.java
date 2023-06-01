class Pair{
    int i, j;
    Pair(int i, int j){
        this.i = i;
        this.j = j;
    }
}

class Solution {
    public int shortestPathBinaryMatrix(int[][] grid) {
        
        int n = grid.length;
        
        if(grid[0][0] != 0 || grid[n-1][n-1] != 0)
            return -1;
        
        Queue<Pair> q = new LinkedList<>();
        q.offer(new Pair(0, 0));
        
        int[][] vis = new int[n][n];
        vis[0][0] = 2;
        
        int dir[][] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
        
        
        int level=0;
        while(q.size()>0){
            
            int size = q.size();
            while(size-- > 0){
                
                Pair p = q.poll();
                
                int i = p.i;
                int j = p.j;
                
                if(i == n-1 && j == n-1){
                    return level + 1;
                }
                
                for(int d=0; d<dir.length; d++){
                    
                    int ni = i + dir[d][0];
                    int nj = j + dir[d][1];
                    
                    if(ni<0 || nj<0 || ni>=n || nj>=n || grid[ni][nj] == 1 || vis[ni][nj] == 2)
                        continue;
                    
                    q.offer(new Pair(ni, nj));
                    vis[ni][nj] = 2;
                }
            }
            
            level ++;
        }
        
        return -1;
    }
}