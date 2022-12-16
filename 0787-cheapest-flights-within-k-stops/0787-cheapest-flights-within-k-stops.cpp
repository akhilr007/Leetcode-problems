class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<pair<int, int>> adj[n];
        for(auto it: flights){
            adj[it[0]].push_back({it[1], it[2]});
        }
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        
        queue<pair<int, pair<int, int>>> q;
        q.push({ 0, {src, 0}}); // [steps, node, dist]
        
        while(!q.empty()){
            
            auto it = q.front();
            q.pop();
            
            int steps = it.first;
            int node = it.second.first;
            int dis = it.second.second;
            
            if(steps > k) continue;
            
            for(auto nbr: adj[node]){
                int adjNode = nbr.first;
                int edgeWeight = nbr.second;
                
                if(dis + edgeWeight < dist[adjNode]){
                    dist[adjNode] = dis + edgeWeight;
                    q.push({steps + 1, {adjNode,  dist[adjNode]}});
                }
            }
        }
        
        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};