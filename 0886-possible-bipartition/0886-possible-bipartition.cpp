class Solution {
public:
    bool checkBipartiteDFS(int node, int color, vector<int>adj[], vector<int>& colors){

        colors[node] = color;

        for(auto adjacentNode: adj[node]){
            if(colors[adjacentNode] == -1){
                if(checkBipartiteDFS(adjacentNode, !color, adj, colors) == false) return false;
            }
            else if(colors[adjacentNode] == color) return false;
        }

        return true;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        vector<int> adj[n+1];
        for(auto it: dislikes){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> colors(n+1, -1);
        
        for(int i=1; i<=n; i++){
            if(colors[i] == -1 and checkBipartiteDFS(i, 0, adj, colors)==false) return false;
        }

        return true;
    }
};