class Solution {
public:
    void dfs(int i, int j, int color, vector<vector<int>>& image, int prevColor){
        
        if(i<0 || j<0 || i>=image.size() || j>=image[0].size() || image[i][j] == color || image[i][j] != prevColor){
            return;
        }
        
        image[i][j] = color;
        dfs(i-1, j, color, image, prevColor);
        dfs(i, j-1, color, image, prevColor);
        dfs(i+1, j, color, image, prevColor);
        dfs(i, j+1, color, image, prevColor);
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        // case1: if the sr,sc has same color as color then return it
        if(image[sr][sc] == color) return image;
        
        dfs(sr, sc, color, image, image[sr][sc]);
        return image;
    }
};