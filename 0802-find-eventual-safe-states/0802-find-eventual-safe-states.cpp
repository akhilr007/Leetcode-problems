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
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
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
};