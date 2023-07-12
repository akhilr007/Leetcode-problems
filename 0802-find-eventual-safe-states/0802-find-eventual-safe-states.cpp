class Solution {
public:
    bool isDFSCycle(int u, vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& inRecursion){
        
        visited[u]=true;
        inRecursion[u]=true;
        
        for(int &v : graph[u]){
            if(!visited[v] and isDFSCycle(v, graph, visited, inRecursion))
                return true;
            else if(inRecursion[v]==true)
                return true;
        }    
        
        inRecursion[u]=false;
        return false;
    }
    
    vector<int> dfs(vector<vector<int>>& graph){
        
        int n = graph.size();
        
        vector<bool> visited(n, false);
        vector<bool> inRecursion(n, false);
        
        for(int i=0; i<n; i++){
            if(!visited[i])
                isDFSCycle(i, graph, visited, inRecursion);
        }
        
        vector<int> safeNodes;
        for(int i=0; i<n; i++)
        {
            if(inRecursion[i]==false)
                safeNodes.push_back(i);
        }
        
        return safeNodes;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n = graph.size();
        
        vector<int> reverseGraph[n]; 
        vector<int> indegree(n);
        // agar terminal node se koi edge hi nai jaa raha to kahn algo se kuch nai hoga
        // iske liye hum graph ko reverse kar sakte hai
        // safe se terminal = terminal se safe(reverse edge)
        for(int i=0; i<n; i++){
            for(int v: graph[i])
            {
                reverseGraph[v].push_back(i);
                indegree[i]++;
            }
        }
        
        queue<int> q;
        // take all indegrees with 0
        for(int i=0; i<n; i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        
        vector<int> safe(n);
        while(!q.empty()){
            
            int u = q.front();
            q.pop();
            safe[u]=1;
            
            for(int v : reverseGraph[u]){
                indegree[v]--;
                
                if(indegree[v]==0)
                    q.push(v);
            
            }
        }
        
        vector<int> result;
        for(int i=0; i<n; i++)
            if(safe[i] == 1)
                result.push_back(i);
        
        return result;
    }
};