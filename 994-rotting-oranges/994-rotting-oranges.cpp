class Solution {
public:
    int find(vector<vector<int>>& grid, queue<pair<int, int>>& q){

        int fresh=0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1){
                    fresh++;
                }
                else if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }

        return fresh;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();

        queue<pair<int, int>> q; // to store rotten oranges index
        int freshOranges = find(grid, q);

        if(freshOranges == 0) return 0;

        int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

        int level = -1;

        while(q.size() > 0){

            int size = q.size();
            level++;

            for(int k=0; k<size; k++){

                auto rem = q.front(); q.pop();

                int i = rem.first;
                int j = rem.second;

                for(int d=0; d<4; d++){
                    int r = i + dir[d][0];
                    int c = j + dir[d][1];

                    if(r>=0 && c>=0 && r<n && c<m && grid[r][c] == 1){
                        q.push({r, c});
                        grid[r][c] = 0;
                        freshOranges--;
                    }
                }
            }
        }

        if(freshOranges==0) return level;
        else return -1;
    }
};