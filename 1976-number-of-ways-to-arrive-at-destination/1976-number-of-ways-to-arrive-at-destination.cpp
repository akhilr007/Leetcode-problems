class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        vector<pair<long, long>> adj[n];
        for(auto it : roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        vector<long> dist(n, LONG_MAX), ways(n, 0);
        ways[0] = 1;
        dist[0] = 0;
        
        priority_queue<pair<long, long>, vector<pair<long, long>>, greater<pair<long, long>>> pq;
        pq.push({ 0, 0}); // {dist, node}
        
        int mod = (long)(1e9+7);
        while(!pq.empty()){
            
            long node = pq.top().second;
            long dis = pq.top().first;
            pq.pop();
            
            for(auto nbr: adj[node]){
                long adjNode = nbr.first;
                long edgeWeight = nbr.second;
                
                if(dis + edgeWeight < dist[adjNode]){
                    dist[adjNode] = dis + edgeWeight;
                    pq.push({ dist[adjNode], adjNode});
                    ways[adjNode] = ways[node];
                }
                else if(dis + edgeWeight == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
                
            }
        }
        
        return (int)ways[n-1] % mod;
    }
};