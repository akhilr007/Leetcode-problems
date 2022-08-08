class Solution {
public:
    void dfs(int src, int n, vector<int>ans, vector<vector<int>>& result, vector<vector<int>>& graph){
        
        ans.push_back(src);
        
        if(src == n-1){
            result.push_back(ans);
            return;
        }
        
        for(auto nbr : graph[src]){
            dfs(nbr, n, ans, result, graph);
        }
        
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        // 2. dfs travel and store the results
        vector<vector<int>> result;
        vector<int> ans;
        int n = graph.size();
        dfs(0, n, ans, result, graph);
        
        return result;
    }
};