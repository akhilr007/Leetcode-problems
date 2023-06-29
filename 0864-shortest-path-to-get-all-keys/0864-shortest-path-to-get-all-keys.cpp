class Solution {
public:
    const int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    int shortestPathAllKeys(vector<string>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        int keysCount = 0;
        queue<vector<int>> q; // {i, j, steps, currentN}
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                
                if(grid[i][j] == '@'){
                    q.push({i, j, 0, 0});
                }
                else if(grid[i][j] >= 'a' and grid[i][j] <= 'f'){
                    keysCount++;
                }
            }
        }
        
        int finalKeysStatusDecimal = pow(2, keysCount) - 1; // pow(2, 3) - 1
        
        int visited[m][n][finalKeysStatusDecimal+1];
        memset(visited, 0, sizeof visited);
        
        
        while(!q.empty()){
            
            auto top = q.front();
            q.pop();
            
            int i = top[0];
            int j = top[1];
            int steps = top[2];
            int currentKeysStatusDecimal = top[3];
            
            if(currentKeysStatusDecimal == finalKeysStatusDecimal)
                return steps;
            
            for(int d=0; d<4; d++){
                
                int ni = i+dir[d][0];
                int nj = j+dir[d][1];
                
                if(ni>=0 && ni<m && nj>=0 && nj<n && grid[ni][nj] != '#'){
                    
                    char ch = grid[ni][nj];
                    
                    if(ch >= 'A' and ch <= 'F'){ // lock
                        if(visited[ni][nj][currentKeysStatusDecimal] == 0 and
                          ((currentKeysStatusDecimal >> (ch-'A')) & 1) == 1){
                            visited[ni][nj][currentKeysStatusDecimal] = 1;
                            q.push({ni, nj, steps+1, currentKeysStatusDecimal});
                        }
                    }
                    else if(ch >= 'a' and ch <= 'f'){ // keys
                        int newKeysStatusDecimal = (1 << (ch-'a')) | currentKeysStatusDecimal;
                        if(visited[ni][nj][newKeysStatusDecimal] == 0){
                            q.push({ni, nj, steps+1, newKeysStatusDecimal});
                            visited[ni][nj][newKeysStatusDecimal] = 1;
                        }
                    }
                    else{
                        if(visited[ni][nj][currentKeysStatusDecimal] == 0){
                            q.push({ni, nj, steps+1, currentKeysStatusDecimal});
                            visited[ni][nj][currentKeysStatusDecimal] = 1;
                        }
                    }
                }
            }
        }
        
        return -1;
    }
};