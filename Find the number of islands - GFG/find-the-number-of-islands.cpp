// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
private:
    int dir[8][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
  public:
    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& vis){

        vis[i][j] = true;

        for(int d=0; d<8; d++){
            int r = i + dir[d][0];
            int c = j + dir[d][1];

            if(r<0 || c<0 || r>=grid.size() || c>=grid[0].size() || grid[r][c] == '0' || vis[r][c] == true){
                continue;
            }

            dfs(r, c, grid, vis);
        }
    }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        int islands=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1' && vis[i][j] == false){
                    dfs(i, j, grid, vis);
                    islands++;
                }
            }
        }

        return islands;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends