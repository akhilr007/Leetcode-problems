class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<int>> efforts(n, vector<int> (m, INT_MAX));
        efforts[0][0] = 0;
        
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.push(make_tuple(0, 0, 0)); // effort, row, col
        
        int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        
        while(pq.size()>0){
            
            auto [currEffort, row, col] = pq.top();
            pq.pop();
            
            if(row == n-1 and col == m-1){
                return currEffort;
            }
            
            for(int d=0; d<4; d++){
                int r = row + dir[d][0];
                int c = col + dir[d][1];
                
                if(r >= 0 and c >= 0 and r < n and c < m){
                    
                    int newEffort = max(currEffort, 
                                        abs(heights[r][c] - heights[row][col]));
                    
                    if(newEffort < efforts[r][c]){
                        efforts[r][c] = newEffort;
                        pq.push(make_tuple(newEffort, r, c));
                    }
                }
            }
        }
        
        return -1;
    }
};