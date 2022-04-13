class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();
        
        queue<pair<int, int>> q;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                if(mat[i][j] == 0){
                    q.push(make_pair(i, j));
                }
                else{
                    mat[i][j] = -1;
                }
            }
        }
        
        int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        
        while(q.size()>0){
            
            auto rem = q.front(); q.pop();
            
            int r = rem.first;
            int c = rem.second;
            
            for(int i=0; i<4; i++){
                int row = r + dir[i][0];
                int col = c + dir[i][1];
                
                if(row >= 0 && col >= 0 && row < n && col < m && mat[row][col] < 0){
                    q.push(make_pair(row, col));
                    mat[row][col] = mat[r][c] + 1;
                }
            }
        }
        
        return mat;
    }
};