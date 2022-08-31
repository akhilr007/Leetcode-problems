class Solution {
    private static void dfs(int r, int c, int[][]heights, int prevHeight, boolean[][] vis){
        
        if(r<0 || c<0 || r>=heights.length || c >= heights[0].length || vis[r][c] == true || prevHeight > heights[r][c]) return;
        
        vis[r][c] = true;
        dfs(r-1, c, heights, heights[r][c], vis);
        dfs(r, c-1, heights, heights[r][c], vis);
        dfs(r+1, c, heights, heights[r][c], vis);
        dfs(r, c+1, heights, heights[r][c], vis);
    }
    
    public List<List<Integer>> pacificAtlantic(int[][] heights) {
        
        int rows = heights.length;
        int cols = heights[0].length;
        
        boolean[][] pacificVisited = new boolean[rows][cols];
        boolean[][] atlanticVisited = new boolean[rows][cols];
        
        for(int r=0; r<rows; r++){
            dfs(r, 0, heights, heights[r][0], pacificVisited);
            dfs(r, cols-1, heights, heights[r][cols-1], atlanticVisited);
        }
        
        for(int c=0; c<cols; c++){
            dfs(0, c, heights, heights[0][c], pacificVisited);
            dfs(rows-1, c, heights, heights[rows-1][c], atlanticVisited);
        }
        
        List<List<Integer>> res = new ArrayList<>();
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(pacificVisited[i][j] == true && atlanticVisited[i][j] == true){
                    List<Integer> ans = new ArrayList<>();
                    ans.add(i);
                    ans.add(j);
                    res.add(ans);
                }
            }
        }
        
        return res;
        
    }
}