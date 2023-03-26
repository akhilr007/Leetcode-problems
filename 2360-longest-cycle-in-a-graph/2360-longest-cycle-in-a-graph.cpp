class Solution {
public:
    void dfs(int src, vector<int>& edges, vector<bool>& vis, 
             vector<bool>& inRecursion, vector<int>& count, int& result){
        
        vis[src] = true;
        inRecursion[src] = true;
        
        
        int nbr = edges[src];
        
        if(nbr != -1 && !vis[nbr]){
            
            count[nbr] = count[src] + 1;
            dfs(nbr, edges, vis, inRecursion, count, result);
        }
        else if(nbr != -1 && inRecursion[nbr] == true){
            
            result = max(result, count[src] - count[nbr] + 1);
        }
        
        inRecursion[src] = false;
    }
    
    int longestCycle(vector<int>& edges) {
        
        int n = edges.size();
        
        vector<bool> vis(n, false), inRecursion(n, false);
        vector<int> count(n, 1);
        
        int result = -1;
        for(int i=0; i<n; i++){
            
            if(!vis[i])
                dfs(i, edges, vis, inRecursion, count, result);
        }
        
        return result;
    }
};