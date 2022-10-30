class Node{
    int r;
    int c;
    int k;
    
    Node(int r, int c, int k){
        this.r = r;
        this.c = c;
        this.k = k;
    }
}

class Solution {
    public int shortestPath(int[][] grid, int k) {
        
        int ROWS = grid.length, COLS = grid[0].length;
        
        if(ROWS == 1 && COLS == 1) return 0;
        
        int[][] dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        
        int[][] kVis = new int[ROWS][COLS];
        
        for(int[] row : kVis) Arrays.fill(row, -1);
        kVis[0][0] = k;
        
        Queue<Node> q = new LinkedList<>();
        q.add(new Node(0, 0, k));
        
        int level=0;
        
        while(q.size() > 0){
            
            int size = q.size();
            while(size-- > 0){
                
                Node curNode = q.poll();
                
                for(int i=0; i<dir.length; i++){
                    int nextRow = curNode.r + dir[i][0];
                    int nextCol = curNode.c + dir[i][1];
                    
                    if(nextRow == ROWS-1 && nextCol == COLS-1) return level+1;
                    
                    if(nextRow >= 0 && nextRow < ROWS && nextCol >= 0 && nextCol < COLS){
                        
                        if(grid[nextRow][nextCol] == 1 && curNode.k > 0 && kVis[nextRow][nextCol] < curNode.k - 1){
                            q.add(new Node(nextRow, nextCol, curNode.k - 1));
                            kVis[nextRow][nextCol] = curNode.k - 1;
                        }
                        else if(grid[nextRow][nextCol] == 0 && kVis[nextRow][nextCol] < curNode.k){
                            q.add(new Node(nextRow, nextCol, curNode.k));
                            kVis[nextRow][nextCol] = curNode.k;
                        }
                    }
                }
            }
            level++;
        }
        
        return -1;
        
    }
}