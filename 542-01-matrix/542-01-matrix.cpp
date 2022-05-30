class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();
      
        queue<pair<int, int>> q;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 0){
                    q.push({i, j}); // push the indexes of 0 to queue
                }
                else{
                    mat[i][j] = -1; // mark all the 1's unvisited by making it -ve
                }
            }
        }

        // four directions
        int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

        while(q.size() > 0){

            auto rem = q.front(); q.pop();
            int i = rem.first;
            int j = rem.second;

            for(int d=0; d<4; d++){
                int r = i + dir[d][0];
                int c = j + dir[d][1];

                if(r >= 0 && c >=0 && r < n && c < m && mat[r][c] == -1){
                    q.push({r, c});
                    mat[r][c] = mat[i][j] + 1;
                }
            }
        }
        
        return mat;
    }
};