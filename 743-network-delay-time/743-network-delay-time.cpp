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
        
        queue<pair<int, int>> q;
        q.push(make_pair(k, 0)); // vertex->weight
        
        vector<int> signal(n+1, INT_MAX);
        signal[k]=0;
        
        while(q.size()>0){
            
            auto rem = q.front();
            q.pop();
            
            int src = rem.first;
            //int wt = rem.second;
            
            for(Edge edge : graph[src]){
                
                int nbr = edge.nbr;
                int time = edge.wt;
                
                int arrivalTime = signal[src] + time;
                if(signal[nbr] > arrivalTime){
                    signal[nbr] = arrivalTime;
                    q.push(make_pair(nbr, time));
                }
            }
        }
        
        int ans=0;
        for(int i=1; i<=n; i++){
            if(signal[i]==INT_MAX) return -1;
            ans = max(ans, signal[i]);
        }
        
        return ans;
    }
};