class Edge{
public:
    int nbr;
    int wt;
    
    Edge(int nbr, int wt){
        this->nbr = nbr;
        this->wt = wt;
    }
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<Edge> graph[n+1];
        
        for(int i=0; i<times.size(); i++){
            int src = times[i][0];
            int nbr = times[i][1];
            int wt = times[i][2];
            
            graph[src].push_back(Edge(nbr, wt));
        }
        
        priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        pq.push({0, k});
        
        vector<bool> vis(n+1, false);
        vector<int> time(n+1, INT_MAX);
        
        while(pq.size()>0){
            
            auto rem = pq.top();
            pq.pop();
            
            int v = rem.second;
            int wsf = rem.first;
            
            if(vis[v] == true) continue;
            vis[v] = true;
            
            time[v] = wsf;
            
            for(Edge edge : graph[v]){
                int nbr = edge.nbr;
                int wt = edge.wt;
                
                if(vis[nbr] == false){
                    int weight = wsf + wt;
                    pq.push({weight, nbr});
                }
            }
        }
        
        int ans;
        for(int i=1; i<n+1; i++){
            if(time[i] == INT_MAX) return -1;
            ans = max(ans, time[i]);
        }
        
        return ans;
    }
};