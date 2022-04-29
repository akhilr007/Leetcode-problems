class Solution {
public:
    bool checkForBipartite(int src, vector<int> adj[], vector<int>& vis){
        
        queue<pair<int, int>> q; // src -> level
        q.push({src, 0});
        
        while(q.size()>0){
            
            auto rem = q.front(); q.pop();
            
            int level = rem.second;
            
            // if the vertex is visited
            if(vis[rem.first] != -1){
                // check the level at vis node if it matches for the rem node
                if(vis[rem.first] != level){
                    return false;
                }
            }
            vis[rem.first] = level;
            
            for(int nbr : adj[rem.first]){
                
                if(vis[nbr] == -1){
                    q.push({nbr, level+1});
                }
            }
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        
        // make graph
        int n = graph.size();
        
        vector<int> adj[n];
        for(int i=0; i<graph.size(); i++){
            for(int j=0; j<graph[i].size(); j++){
                
                int u = i;
                int v = graph[i][j];
                
                adj[u].push_back(v);
            }
        }
        
        vector<int> vis(n, -1);
        
        for(int i=0; i<n; i++){
            if(vis[i] == -1){
                bool isCompBipartite = checkForBipartite(i, adj, vis);
                if(isCompBipartite == false){
                    return false;
                }
            }
        }
        
        return true;
    }
};