//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis, 
    vector<pair<int, int>>& vec, int row0, int col0){
        
        vis[row][col] = 1;
        vec.push_back({row0 - row, col0 - col});
        
        int N = grid.size();
        int M = grid[0].size();
        
        vector<vector<int>> delta = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        for(int i=0; i<4; i++){
            int nrow = row + delta[i][0];
            int ncol = col + delta[i][1];
            
            if(nrow >= 0 && ncol >= 0 && nrow < N && ncol < M && vis[nrow][ncol] == 0 &&
            grid[nrow][ncol] == 1){
                dfs(nrow, ncol, grid, vis, vec, row0, col0);
            }
        }
    }
    
    int countDistinctIslands(vector<vector<int>>& grid) {
        
        int N = grid.size();
        int M = grid[0].size();
        
        vector<vector<int>> vis(N, vector<int> (M, 0));
        set<vector<pair<int, int>>> st;
        
        
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                
                if(vis[i][j] == 0 && grid[i][j] == 1){
                    
                    vector<pair<int, int>> vec;
                    dfs(i, j, grid, vis, vec, i, j);
                    st.insert(vec);
                }
            }
        }
        
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends