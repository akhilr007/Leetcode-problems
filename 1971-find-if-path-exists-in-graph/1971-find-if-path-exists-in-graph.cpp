class Solution {
public:
    void dfs(int node, vector<int>& vis, vector<int> adj[], int destination){
        
        if(vis[destination] == true) return;
        vis[node] = true;
        for(auto adjNode: adj[node]){
            if(!vis[adjNode]){
                dfs(adjNode, vis, adj, destination);
            }
        }
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        
        // create a adjacency list
        vector<int> adj[n];
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> vis(n, 0);
        dfs(source, vis, adj, destination);
        
        if(vis[destination] == 1) return true;
        return false;
    }
};