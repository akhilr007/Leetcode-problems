class Solution {
public:
    void buildGraph(vector<vector<int>>& edges, vector<int> adj[], int n){
        
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
    }
    
    void dfs(int node, int par, vector<int> adj[], vector<int>& childNodes){
        
        for(auto adjNode: adj[node]){
            if(adjNode != par){
                dfs(adjNode, node, adj, childNodes);
                childNodes[node] += childNodes[adjNode];
            }
        }
    }
    
    int bfs(int src, vector<int> adj[], int n){
        
        queue<pair<int, int>> q;
        vector<int> vis(n, 0);
        vis[src] = 1;
        q.push({src, 0});
        
        int sum = 0;
        while(!q.empty()){
            
            int node = q.front().first;
            int dist = q.front().second;
            q.pop();
            
            sum += dist;
            
            for(auto adjNode: adj[node]){
                if(!vis[adjNode]){
                    q.push({adjNode, dist+1});
                    vis[adjNode] = 1;
                }
            }
        }
        
        return sum;
    }
    
    void bfs(vector<int> adj[], vector<int>& ans, vector<int>& childNodes){
        
        queue<int> q;
        q.push(0);
        
        int n = ans.size();
        vector<int> vis(n, 0);
        vis[0] = 1;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto adjNode: adj[node]){
                if(!vis[adjNode]){
                    q.push(adjNode);
                    vis[adjNode] = 1;
                    ans[adjNode] = ans[node] - childNodes[adjNode] + (n - childNodes[adjNode]);
                }
            }
        }
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        
        vector<int> adj[n];
        buildGraph(edges, adj, n);
        
        vector<int> childNodes(n); // count of child nodes including itself
        for(int i=0; i<n; i++) childNodes[i] = 1;
        dfs(0, -1, adj, childNodes);
        
        vector<int> ans(n,0);
        ans[0] = bfs(0, adj, n);
        
        bfs(adj, ans, childNodes);
        
        return ans;
    }
};