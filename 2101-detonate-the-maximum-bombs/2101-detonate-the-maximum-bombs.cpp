class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<bool>& visited, int& count){
        
        visited[node] = true;
        count++;
        
        for(auto adjNode: adj[node]){
            
            if(visited[adjNode] == false){
                dfs(adjNode, adj, visited, count);
            }
        }
    }
    
    int maximumDetonation(vector<vector<int>>& bombs) {
        
        int n = bombs.size();
        
        vector<int> adj[n];
        
        for(int i=0; i<n; i++){
            
            for(int j=0; j<n; j++){
                
                if(i == j)
                    continue;
                
                long long x1 = bombs[i][0];
                long long y1 = bombs[i][1];
                long long r1 = bombs[i][2];
                
                long long x2 = bombs[j][0];
                long long y2 = bombs[j][1];
                long long r2 = bombs[j][2];
                
                long long distance = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
                
                if((long long) r1 * r1 >= distance){
                    adj[i].push_back(j);
                }
            }
        }
        
        int result = 0;
        vector<bool> visited(n, false);
        
        for(int i=0; i<n; i++){
            
            int count = 0;
            dfs(i, adj, visited, count);
            
            result = max(result, count);
            
            for(int i=0; i<n; i++){
                visited[i] = false;
            }
        }
        
        return result;
    }
};