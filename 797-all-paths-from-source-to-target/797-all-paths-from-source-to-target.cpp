class Solution {
public:
    void dfs(int src, int n, vector<int>ans, vector<vector<int>>& result, vector<int> adj[]){
        
        ans.push_back(src);
        
        if(src == n-1){
            result.push_back(ans);
            return;
        }
        
        for(auto nbr : adj[src]){
                dfs(nbr, n, ans, result, adj);
        }
        
        ans.pop_back();
        
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        // 1. construct the graph
        int n = graph.size();
        vector<int> adj[n];
        for(int i=0; i<n; i++){
            int src = i;
            for(int j=0; j<graph[i].size(); j++){
                int nbr = graph[i][j];
                adj[i].push_back(nbr);
            }
        }
        
        // 2. dfs travel and store the results
        vector<vector<int>> result;
        vector<int> ans;
        dfs(0, n, ans, result, adj);
        
        return result;
    }
};