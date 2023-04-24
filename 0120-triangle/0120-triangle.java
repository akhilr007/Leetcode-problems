class Solution {
public:
    int f(int i, int j, int n, vector<vector<int>>& triangle, 
         vector<vector<int>>& dp){
        
        if(i == n-1) return triangle[i][j];
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int down = triangle[i][j] + f(i+1, j, n, triangle, dp);
        int downRight = triangle[i][j] + f(i+1, j+1, n, triangle, dp);
        
        return dp[i][j] = min(down, downRight);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n=triangle.size();
        
        vector<int> cur(n, 0), front(n, 0);
        
        for(int j=0; j<n; j++)
            front[j] = triangle[n-1][j];
        
        for(int i=n-2; i>=0; i--){
            for(int j=i; j>=0; j--){
                
                int down = triangle[i][j] + front[j];
                int downRight = triangle[i][j] + front[j+1];
                
                cur[j] = min(down, downRight);
            }
            
            front = cur;
        }
        
        return front[0];
    }
};