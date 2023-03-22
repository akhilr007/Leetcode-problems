class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        
        vector<pair<int, int>> adj[n+1];
        
        for(auto &it: roads){
            
            int src = it[0];
            int nbr = it[1];
            int dist = it[2];
            
            adj[src].push_back({nbr, dist});
            adj[nbr].push_back({src, dist});
        }
        
        queue<int> q;
        q.push(1);
        
        int minScore = INT_MAX;
        vector<int> vis(n+1, 0);
        vis[1] = 1;
        
        while(!q.empty()){
            
            int size = q.size();
            while(size--){
                
                int src = q.front();
                q.pop();
                
                for(auto& adjNode: adj[src]){
                    
                    int nbr = adjNode.first;
                    int dist = adjNode.second;
                    minScore = min(minScore, dist);
                    
                    if(vis[nbr] == 0){
                        q.push(nbr);
                        vis[nbr] = 1;
                    }
                }
            }
        }
        
        return minScore;
    }
};