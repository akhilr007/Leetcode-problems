class Solution {
public:
    pair<int, int> getCoordinates(int num, int n){
        
        int RT = (num - 1) / n; // row from top
        int RB = (n - 1) - RT; // row from bottom
        
        int col = (num - 1) % n;
        if((RB%2==0 && n%2==0) or (RB%2==1 && n%2==1))
            col = (n - 1) - col;
        
        return make_pair(RB, col);
    }
    
    int snakesAndLadders(vector<vector<int>>& board) {
        
        int n = board.size();
        
        queue<pair<int, int>> q; // {node, time}
        q.push({1, 0}); 
        
        vector<vector<int>> vis(n, vector<int> (n, 0));
        vis[n-1][0] = 1;
        
        int min_steps = 0;
        
        while(!q.empty()){
            
            auto it = q.front();
            q.pop();
            
            int node = it.first;
            int t = it.second;
            
            min_steps = max(t, min_steps);
            
            if(node == n * n){
                return min_steps;
            }
            
            for(int k=1; k<=6; k++){
                
                int val = node + k;
                
                if(val > n*n)
                    break;
                
                pair<int, int> coord = getCoordinates(val, n);
                
                int r = coord.first;
                int c = coord.second;
                
                if(vis[r][c] == 1)
                    continue;
                
                vis[r][c] = 1;
                if(board[r][c] == -1){
                    q.push({val, t + 1});
                }
                else
                    q.push({board[r][c], t+1});
                
            }
        
        }
        
        return -1;
    }
};