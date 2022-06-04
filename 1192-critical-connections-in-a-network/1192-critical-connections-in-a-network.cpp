class Solution {
public:
    void dfs(vector<int> adj[], int src, int par, vector<bool>& vis, vector<int>& disc, vector<int>& low,
    int& t, vector<vector<int>>& servers){

        disc[src] = low[src] = t;
        t++;

        vis[src] = true;

        for(int nbr : adj[src]){

            if(par == nbr) continue;

            else if(vis[nbr] == true){
                low[src] = min(low[src], disc[nbr]);
            }

            else{
                dfs(adj, nbr, src, vis, disc, low, t, servers);
                low[src] = min(low[src], low[nbr]);

                if(low[nbr] > disc[src]){
                    vector<int> edges;
                    edges = {nbr, src};
                    servers.push_back(edges);
                }
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {

        vector<int> adj[n];
        for(int i=0; i<connections.size(); i++){
            int u = connections[i][0];
            int v = connections[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<vector<int>> servers;

        vector<bool> vis(n, false);
        vector<int> disc(n, 0), low(n, 0);

        int par=-1;
        int t=0;

        dfs(adj, 0, par, vis, disc, low, t, servers);

        return servers;
    }
};