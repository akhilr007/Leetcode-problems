struct Pair{
    int diff;
    int row;
    int col;
    
    Pair(int diff, int row, int col){
        this->diff = diff;
        this->row = row;
        this->col = col;
    }
};

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<int>> dist(n, vector<int> (m, 1e9));
        
        auto lambda = [&](Pair p1, Pair p2){
            return p1.diff > p2.diff;
        };
        
        priority_queue<Pair, vector<Pair>, decltype(lambda)> pq(lambda);
        Pair p = Pair(0, 0, 0);
        pq.push(p); // [diff, row, col]
        
        dist[0][0] = 0;
        
        int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        
        while(!pq.empty()){
            
            auto it = pq.top();
            pq.pop();
            
            int row = it.row;
            int col = it.col;
            int diff = it.diff;
            
            if(row == n-1 && col == m-1) return diff;
            
            for(int i=0; i<4; i++){
                
                int new_row = row + dir[i][0];
                int new_col = col + dir[i][1];
                
                if(new_row>=0 && new_col >= 0 && new_row<n && new_col<m){
                    
                    int new_effort = max(abs(heights[row][col] - heights[new_row][new_col]), diff);
                    
                    if(new_effort < dist[new_row][new_col]){
                        dist[new_row][new_col] = new_effort;
                        Pair p = Pair(new_effort, new_row, new_col);
                        pq.push(p);
                    }
                }
            }
        }
        
        return 0;
    }
};