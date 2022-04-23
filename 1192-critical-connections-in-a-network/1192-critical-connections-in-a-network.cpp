class Solution {
public:
    
    void helperUtil(vector<int> graph[], int src, int par, vector<bool>& vis, vector<int>& disc, vector<int>& low, int t, vector<vector<int>>& ans){
        
        disc[src] = low[src] = t;
        vis[src] = true;
        t++;
        
        for(int nbr : graph[src]){
            
            if(nbr == par){
                continue;
            }
            
            else if(vis[nbr] == true){
                low[src] = min(low[src], disc[nbr]);
            }
            
            else{
                helperUtil(graph, nbr, src, vis, disc, low, t, ans);
                low[src] = min(low[src], low[nbr]);
                
                if(low[nbr] > disc[src]){
                    vector<int> edge;
                    edge.push_back(src);
                    edge.push_back(nbr);
                    ans.push_back(edge);
                }
            }
        }
        
    }
    
    vector<vector<int>> findBridge(vector<int> graph[], int n){
        
        vector<vector<int>> ans;
        
        vector<int> disc(n), low(n);
        vector<bool> vis(n, false);
        
        int t=0;
        int par=-1;
        int src=0;
        
        helperUtil(graph, src, par, vis, disc, low, t, ans);
        return ans;
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        vector<int> graph[n];
        
        for(int i=0; i<connections.size(); i++){
            int u = connections[i][0];
            int v = connections[i][1];
            
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        vector<vector<int>> ans = findBridge(graph, n);
        return ans;
    }
};