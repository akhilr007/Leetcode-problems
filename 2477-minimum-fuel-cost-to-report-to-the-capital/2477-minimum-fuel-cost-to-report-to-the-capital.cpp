class Solution {
public:
    long long res;
    int dfs(int node, int par, vector<int> adj[], int seats){
        
        int passengers = 0;
        
        for(int& child: adj[node]){
            if(child != par){
                
                int p = dfs(child, node, adj, seats);
                
                passengers += p;
                
                res += (int)ceil(p*1.0/seats);
            }
        }
        
        return passengers + 1;
    }
    
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        
        int n = roads.size();
        vector<int> adj[n+1];
        for(auto it : roads){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        res = 0;
        dfs(0, -1, adj, seats);
        
        return res;
    }
};