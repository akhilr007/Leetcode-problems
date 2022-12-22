class Solution {
public:
    int bfs(int src, vector<int> adj[], int n){
        
        queue<pair<int, int>> q;
        q.push({src, 0});
        
        vector<int> vis(n, 0);
        vis[src] = 1;
        
        int sum=0;
        while(!q.empty()){
            
            auto it = q.front();
            q.pop();
            int node = it.first;
            int dist = it.second;
            
            sum += dist;
            
            for(auto adjNode: adj[node]){
                if(!vis[adjNode]){
                    q.push({adjNode, dist + 1});
                    vis[adjNode] = 1;
                }
            }
        }
        return sum;
    }
    
    void calculateSubtree(int node, int par, vector<int> adj[], vector<int>& subtrees){
        
        for(auto adjNode: adj[node]){
            if(adjNode != par){
                calculateSubtree(adjNode, node, adj, subtrees);
                subtrees[node] += subtrees[adjNode];
            }
        }
    }
    
    void bfs2(int src, vector<int> adj[], vector<int>& subtrees, vector<int>& ans){
        
        queue<int> q;
        q.push(src);
        
        int n = subtrees.size();
        vector<int> vis(n, 0);
        vis[src] = 1;
        
        while(!q.empty()){
            
            int node = q.front();
            q.pop();
            
            for(auto adjNode: adj[node]){
                if(!vis[adjNode]){
                    q.push(adjNode);
                    vis[adjNode] = 1;
                    ans[adjNode] = ans[node] - subtrees[adjNode] + ( n - subtrees[adjNode]); 
                }
            }
        }
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        
        vector<int> adj[n];
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> ans(n, 0);
        ans[0] = bfs(0, adj, n);
        
        vector<int> subtrees(n, 1);
        calculateSubtree(0, -1, adj, subtrees);
        
        bfs2(0, adj, subtrees, ans);
        
        return ans;
    }
};