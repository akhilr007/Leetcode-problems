class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        
        int n = graph.size();
        if(n == 1) return 0;
        int finalState = (1 << n) - 1;
        
        queue<tuple<int, int>> q;
        
        for(int i=0; i<n; i++){
            q.push(make_tuple(i, (1<<i)));
        }
        
        vector<vector<int>> vis(n, vector<int> (finalState + 1, 0));
        
        int shortestPath = 0;
        while(!q.empty()){
            int size = q.size();
            shortestPath++;
            
            for(int i=0; i<size; i++){
                
                auto [node, visState] = q.front();
                q.pop();
                
                for(auto nbr: graph[node]){
                    
                    int newVisState = visState | (1<<nbr);
                    
                    if(vis[nbr][newVisState] == 1) continue;
                    vis[nbr][newVisState] = 1;
                    
                    if(newVisState == finalState) return shortestPath;
                    
                    q.push(make_tuple(nbr, newVisState));
                }
            }
        }
        
        return -1;
    }
};