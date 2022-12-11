class Solution {
public:
    bool checkBipartite(int start, vector<vector<int>> graph, int colors[]){
        
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
    
    bool isBipartite(vector<vector<int>>& graph) {
        
        // create an adjacency list
        int n = graph.size();
        int colors[n];
        for(int i=0; i<n; i++) colors[i] = {-1};
        
        for(int i=0; i<n; i++){
            if(colors[i] == -1){
                if(checkBipartite(i, graph, colors)==false) return false;
            }
        }
        
        return true;
    }
};