class Solution {
    private void dfs(int row, int col, int[][] image, int[][] ans, int newColor, int initialColor, int[][] delta){
        
        ans[row][col] = newColor;
        int N = image.length;
        int M = image[0].length;
        
        for(int i=0; i<delta.length; i++){
            int nrow = row + delta[i][0];
            int ncol = col + delta[i][1];
            
            if(nrow >= 0 && nrow < N && ncol >= 0 && ncol < M && image[nrow][ncol] == initialColor && ans[nrow][ncol] != newColor){
                dfs(nrow, ncol, image, ans, newColor, initialColor, delta);
            }
        }
    }
    
    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        
        if(image[sr][sc] == newColor) return image;
        
        int[][] ans = image;
        int initialColor = image[sr][sc];
        int[][] delta = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        
        dfs(sr, sc, image, ans, newColor, initialColor, delta);
        return ans;
    }
}