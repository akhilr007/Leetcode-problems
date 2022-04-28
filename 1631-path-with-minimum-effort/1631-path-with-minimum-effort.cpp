class Solution {
public:
    bool dfs(int i, int j, vector<vector<int>>& heights, vector<vector<bool>>& vis, int mid, int n, int m)     
    {
        
        vis[i][j] = true;
        
        if(i==n && j==m){
            return true;
        }
        
        bool op = false;
        
        if(i>0 && vis[i-1][j] == false && abs(heights[i][j] - heights[i-1][j]) <= mid){
            op = op || dfs(i-1, j, heights, vis, mid, n, m);
        }
        if(j>0 && vis[i][j-1] == false && abs(heights[i][j] - heights[i][j-1]) <= mid){
            op = op || dfs(i, j-1, heights, vis, mid, n, m);
        }
        if(i<n && vis[i+1][j] == false && abs(heights[i][j] - heights[i+1][j]) <= mid){
            op = op || dfs(i+1, j, heights, vis, mid, n, m);
        }
        if(j<m && vis[i][j+1] == false && abs(heights[i][j] - heights[i][j+1]) <= mid){
            op = op || dfs(i, j+1, heights, vis, mid, n, m);
        }
        
        return op;
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int maxi = INT_MIN;
        
        for(int i=0; i<heights.size(); i++){
            for(int j=0; j<heights[0].size(); j++){
                maxi = max(maxi, heights[i][j]);
            }
        }
        
        int start=0;
        int end=maxi;
        
        int n=heights.size();
        int m=heights[0].size();
        
        int ans=INT_MAX;
        while(start <= end){
            
            vector<vector<bool>> vis(n, vector<bool>(m, false));
            int mid = start + (end-start)/2;
            
            if(dfs(0, 0, heights, vis, mid, n-1, m-1)){
                ans = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        
        return ans;
    }
};