//{ Driver Code Starts
// Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;

// Position this line where user code will be pasted.

class GFG {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while (T-- > 0) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            int[][] grid = new int[n][m];

            for (int i = 0; i < n; i++) {

                for (int j = 0; j < m; j++) {
                    grid[i][j] = sc.nextInt();
                }
            }

            Solution ob = new Solution();
            int ans = ob.countDistinctIslands(grid);
            System.out.println(ans);
        }
    }
}
// } Driver Code Ends


// User function Template for Java
class Pair{
    int row;
    int col;
    
    Pair(int row, int col){
        this.row = row;
        this.col = col;
    }
}

class Solution {
    
    public void dfs(int row, int col, int[][] grid, int[][] vis, ArrayList<String> vec, int row0, int col0){
        
        vis[row][col] = 1;
        vec.add(toString(row0 - row, col0 - col));
        
        int N = grid.length;
        int M = grid[0].length;
        
        int[][] delta = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        for(int i=0; i<4; i++){
            int nrow = row + delta[i][0];
            int ncol = col + delta[i][1];
            
            if(nrow >= 0 && nrow < N && ncol >= 0 && ncol < M && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
                dfs(nrow, ncol, grid, vis, vec, row0, col0);
            }
        }
    }
    
    private String toString(int r, int c){
        return Integer.toString(r) + " " + Integer.toString(c);
    }

    int countDistinctIslands(int[][] grid) {
        
        int N = grid.length;
        int M = grid[0].length;
        
        int[][] vis = new int[N][M];
        HashSet<ArrayList<String>> st = new HashSet<>();
        
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                
                if(vis[i][j] == 0 && grid[i][j] == 1){
                    ArrayList<String> vec = new ArrayList<>();
                    dfs(i, j, grid, vis, vec, i, j);
                    st.add(vec);
                }
            }
        }
        
        return st.size();
    }
}
