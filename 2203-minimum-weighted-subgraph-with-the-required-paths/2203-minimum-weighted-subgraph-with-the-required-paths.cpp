class Edge{
public:
    int nbr, wt;
    Edge(int nbr, int wt){
        this->nbr = nbr;
        this->wt = wt;
    }
};

class Solution {
public:
    void dijsktra(vector<Edge> graph[], int src, vector<long>& d, vector<bool> vis){
        
        priority_queue<pair<long, long>, vector<pair<long, long>>, greater<pair<long, long>>> pq;
        
        pq.push({0, src});
        
        while(pq.size() > 0){
            
            auto rem = pq.top();
            pq.pop();
            
            long wt = rem.first;
            long node = rem.second;
            
            if(vis[node] == true) continue;
            vis[node] = true;
            d[node] = wt;
            
            for(auto edge : graph[node]){
                
                long nbr = (long)edge.nbr;
                long weight = (long)edge.wt;
                
                if(vis[nbr] == false){
                    
                    long newWeight = wt + weight;
                    pq.push({newWeight, nbr});
                }
            }
        }
    }
    
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        
        // 1. create graph and reverse graph(to calculate min dist from dest to all other nodes)
        vector<Edge> graph[n], reverseGraph[n];
        for(int i=0; i<edges.size(); i++){
            int src = edges[i][0];
            int nbr = edges[i][1];
            int wt = edges[i][2];
            
            graph[src].push_back(Edge(nbr, wt));
            reverseGraph[nbr].push_back(Edge(src, wt));
        }
        
        vector<long> da(n, LONG_MAX), db(n, LONG_MAX), dc(n, LONG_MAX);
        vector<bool> vis(n, false);
        dijsktra(graph, src1, da, vis);
        dijsktra(graph, src2, db, vis);
        dijsktra(reverseGraph, dest, dc, vis);
        
        long ans = LONG_MAX;
        for(int i=0; i<n; i++){
            if(da[i] == LONG_MAX or db[i] == LONG_MAX or dc[i] == LONG_MAX) continue;
            long minWt = da[i] + db[i] + dc[i];
            ans = min(ans, minWt);
        }
        
        return ans == LONG_MAX ? -1 : ans;
    }
};