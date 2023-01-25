class Solution {
public:
    void dfs(vector<int>& edges, int node, vector<bool>& vis, vector<int>& dist){
        
        vis[node] = true;
        
        int adjNode = edges[node];
        
        if(adjNode != -1 and !vis[adjNode]){
            dist[adjNode]= 1 + dist[node];
            dfs(edges, adjNode, vis, dist);
        }
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        
        int n = edges.size();
        
        vector<int> dist1(n, INT_MAX);
        vector<int> dist2(n, INT_MAX);
        
        dist1[node1] = 0;
        dist2[node2] = 0;
        
        vector<bool> vis1(n, false);
        vector<bool> vis2(n, false);
        
        dfs(edges, node1, vis1, dist1);
        dfs(edges, node2, vis2, dist2);
        
        int minDistNode = -1;
        int minDistanceTillNow = INT_MAX;
        
        for(int i=0; i<n; i++){
            int maxD = max(dist1[i], dist2[i]);
            
            if(minDistanceTillNow > maxD){
                minDistNode = i;
                minDistanceTillNow = maxD;
            }
        }
        
        return minDistNode;
    }
};