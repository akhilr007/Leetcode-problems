class Solution {
public:
    void dfs(int node, int parent, vector<pair<int, int>> adj[], int& cnt){
        
        for(auto &p : adj[node]){
            
            int adjNode = p.first;
            int isOriginalEdge = p.second;
            
            if(adjNode == parent)
                continue;
            
            if(isOriginalEdge == 1)
                cnt++;
            
            dfs(adjNode, node, adj, cnt);
        }
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        
        vector<pair<int, int>> adj[n];
        
        for(auto& it: connections){
            adj[it[0]].push_back({it[1], 1}); // original edge
            adj[it[1]].push_back({it[0], 0}); // fake edge
        }
        
        int cnt=0;
        dfs(0, -1, adj, cnt);
        return cnt;
    }
};