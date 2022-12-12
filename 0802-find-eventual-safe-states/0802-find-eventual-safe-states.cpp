class Solution {
public:
    bool dfsCheck(int node, vector<vector<int>>& graph, int vis[], int pathVis[]){
        
        vis[node] = 1;
        pathVis[node] = 1;
        
        for(auto& adjacentNode: graph[node]){
            if(vis[adjacentNode] == 0){
                if(dfsCheck(adjacentNode, graph, vis, pathVis) == true){
                    return true;
                }
            }
            else if(pathVis[adjacentNode] == 1){
                return true;
            }
        }
        
        pathVis[node] = 0;
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int N = graph.size();
        int vis[N], pathVis[N];
        for(int i=0; i<N; i++){
            vis[i] = 0;
            pathVis[i] = 0;
        }
        
        vector<int> safeNodes;
        for(int i=0; i<N; i++){
            if(vis[i] == 0){
                dfsCheck(i, graph, vis, pathVis);
            }
        }
        
        for(int i=0; i<N; i++){
            if(pathVis[i] == 0) safeNodes.push_back(i);
        }
        
        return safeNodes;
    }
};