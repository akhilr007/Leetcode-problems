class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        
        int n = colors.size();
        vector<int> adj[n];
        
        vector<int> indegree(n, 0);
        for(auto edge: edges){
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }
        
        queue<int> q;
        vector<vector<int>> t(n, vector<int> (26, 0));
        // t[u][v] -> max color value of v ending at u
        for(int i=0; i<n; i++){
            if(indegree[i] == 0){
                q.push(i);
                t[i][colors[i]-'a'] = 1;
            }
        }
        
        int ans = 0;
        int countNodes = 0;
        
        while(!q.empty()){
            
            int node = q.front();
            q.pop();
            
            countNodes++;
            
            ans = max(ans, t[node][colors[node]-'a']);
            
            for(auto adjNode: adj[node]){
                
                // update colors from a, b... z
                for(int i=0; i<26; i++){
                    
                    t[adjNode][i] = max(t[adjNode][i], t[node][i] + (colors[adjNode]-'a' == i));
                }
                
                indegree[adjNode]--;
                if(indegree[adjNode] == 0) q.push(adjNode);
            }
            
        }
        
        if(countNodes < n) return -1;
        return ans;
    }
};