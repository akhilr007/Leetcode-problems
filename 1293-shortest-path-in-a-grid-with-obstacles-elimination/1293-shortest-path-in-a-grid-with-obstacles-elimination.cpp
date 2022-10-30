class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        if(n == 1 && m == 1) return 0;
        
        queue<tuple<int,int,int>> q;
        q.push({0, 0, k});
        
        int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        vector<vector<int>> kVis(n, vector<int>(m, -1));
        kVis[0][0] = k;
        
        int level=0;
        while(q.size() > 0){
            
            int size=q.size();
            while(size-- > 0){
                
                auto [curRow, curCol, curK] = q.front();
                q.pop();
                
                for(int i=0; i<4; i++){
                    int nextRow = curRow + dir[i][0];
                    int nextCol = curCol + dir[i][1];
                    
                    if(nextRow == n-1 && nextCol == m-1) return level+1;
                    
                    if(nextRow >= 0 && nextRow < n && nextCol >= 0 && nextCol < m){
                        
                        if(grid[nextRow][nextCol] == 1 && curK>0 && kVis[nextRow][nextCol] < (curK - 1)){
                            q.push({nextRow, nextCol, curK-1});
                            kVis[nextRow][nextCol] = curK - 1;
                        }
                        
                        else if(grid[nextRow][nextCol] == 0 && kVis[nextRow][nextCol] < (curK)){
                            q.push({nextRow, nextCol, curK});
                            kVis[nextRow][nextCol] = curK;
                        }
                    }
                }
            }
            level++;
        }
        
        return -1;
    }
};