class Solution {
public:
    
    void dfs(int src, vector<int> graph[], vector<bool>& vis, int& scs){
        scs++;
        vis[src] = true;
        
        for(int nbr : graph[src]){
            if(vis[nbr] == false){
                dfs(nbr, graph, vis, scs);
            }
        }
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        
        vector<int> graph[n];
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        vector<bool> vis(n, false);
        
        vector<int> componentsSize;
        
        for(int i=0; i<n; i++){
            if(vis[i] == false){
                int scs=0;
                
                dfs(i, graph, vis, scs);
                componentsSize.push_back(scs);
            }
        }
        
        if(componentsSize.size() <= 1) return 0;
        long long count=0;
        vector<int> sum(componentsSize.size(), 0);
        sum[componentsSize.size()-1] = componentsSize[componentsSize.size()-1];
        for(int i=componentsSize.size()-2; i>=0;  i--){
            sum[i] = componentsSize[i] + sum[i+1];
        }
        
        for(int i=0; i<componentsSize.size()-1; i++){
            count += (long long)componentsSize[i]*(long long)sum[i+1];
        }
        
        return count;
        
    }
};