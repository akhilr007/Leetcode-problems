class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<int>& informTime, int count, int& result){
        
        for(auto employee : adj[node]){
            
            dfs(employee, adj, informTime, count+informTime[node], result);
        }
        
        result = max(result, count);
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        vector<int> adj[n];
        
        for(int i=0; i<n; i++){
            if(manager[i] == -1)
                continue;
            adj[manager[i]].push_back(i);
        }
        
        int result = 0;
        
        dfs(headID, adj, informTime, 0, result);
        
        return result;
    }
};