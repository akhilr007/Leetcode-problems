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
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<Edge> adj[n+1];
        for(int i=0; i<times.size(); i++){
            int src = times[i][0];
            int nbr = times[i][1];
            int wt = times[i][2];
            
            adj[src].push_back(Edge(nbr, wt));
        }
        
        priority_queue<pair<int, int>,vector<pair<int, int>>, greater<pair<int,int>>> pq; // {weight, node}
        unordered_set<int> visit;
        pq.push({0, k});
        
        int t=0;
        
        while(!pq.empty()){
            
            auto rem = pq.top();
            pq.pop();
            
            int wt = rem.first;
            int src = rem.second;
            
            if(visit.find(src) != visit.end()) continue;
            visit.insert(src);
            
            t = max(t, wt);
            
            for(auto edge : adj[src]){
                int nbr = edge.nbr;
                int w1 = edge.wt;
                
                if(visit.find(nbr) == visit.end()){
                    int weight = w1+wt;
                    pq.push({weight, nbr});
                }
            }
        }
        
        if(visit.size() == n) return t;
        else return -1;
    }
};