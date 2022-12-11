class Solution {
public:
    bool checkBipartiteBFS(int start, vector<vector<int>> graph, int colors[]){
        
        queue<int> q;
        q.push(start);
        colors[start] = 0;
        
        while(!q.empty()){
            
            int node = q.front();
            q.pop();
            
            for(auto adjacentNode: graph[node]){
                // if the node has yet not been colored
                // then color it with different colors than its adjacent node
                if(colors[adjacentNode] == -1){
                    colors[adjacentNode] = !colors[node];
                    q.push(adjacentNode);
                }
                else if(colors[adjacentNode] == colors[node]){
                    return false;
                }
            }
        }
        return true;
    }
    
    bool checkBipartiteDFS(int node, int color, vector<vector<int>>& graph, int colors[]){
        
        colors[node] = color;
        
        for(auto adjacentNode: graph[node]){
            if(colors[adjacentNode] == -1){
                if(checkBipartiteDFS(adjacentNode, !color, graph, colors)==false)
                    return false;
            }
            else if(colors[adjacentNode] == color) return false;
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        
        // create an adjacency list
        int n = graph.size();
        int colors[n];
        for(int i=0; i<n; i++) colors[i] = -1;
        
        for(int i=0; i<n; i++){
            if(colors[i] == -1){
                if(checkBipartiteDFS(i, 0, graph, colors)==false) return false;
            }
        }
        
        return true;
    }
};