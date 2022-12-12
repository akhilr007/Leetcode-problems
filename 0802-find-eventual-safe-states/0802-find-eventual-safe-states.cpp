class Solution {
public:
    bool dfsCheck(int node, vector<vector<int>>& graph, int vis[], int pathVis[], int check[]){
        
        if(check[node] == 1) return true;
        vis[node] = 1;
        pathVis[node] = 1;
        
        for(auto& adjacentNode: graph[node]){
            if(vis[adjacentNode] == 0){
                if(dfsCheck(adjacentNode, graph, vis, pathVis, check) == true){
                    check[adjacentNode] = 1;
                    return true;
                }
            }
            else if(pathVis[adjacentNode] == 1){
                check[adjacentNode] = 1;
                return true;
            }
        }
        
        
        pathVis[node] = 0;
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int N = graph.size();
        int vis[N], pathVis[N], check[N];
        for(int i=0; i<N; i++){
            vis[i] = 0;
            pathVis[i] = 0;
            check[i] = 0;
        }
        
        vector<int> safeNodes;
        for(int i=0; i<N; i++){
            if(vis[i] == 0){
                dfsCheck(i, graph, vis, pathVis, check);
            }
        }
        
        for(int i=0; i<N; i++){
            if(pathVis[i] == 0) safeNodes.push_back(i);
        }
        
        return safeNodes;
    }
};