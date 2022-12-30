class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, vector<int>& vis, vector<vector<int>>& allPaths, vector<int> path){
        
        if(node == graph.size() - 1){
            path.push_back(node);
            allPaths.push_back(path);
            return;
        }
        
        path.push_back(node);
        vis[node] = 1;
        
        for(auto adjNode: graph[node]){
            if(vis[adjNode] == 0){
                dfs(adjNode, graph, vis, allPaths, path);
            }
        }
        
        vis[node] = 0;
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int> vis(n, 0); // 0 -> not visited
        
        vector<vector<int>> allPaths;
        
        vector<int> path;
        dfs(0, graph, vis, allPaths, path);
        return allPaths;
    }
};