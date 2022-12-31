//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
private:
    int timer=0;
    void dfs(int node, int parent, vector<int> adj[], vector<int>& vis, 
    int tin[], int low[], vector<vector<int>>& bridges){
        
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        
        for(auto it: adj[node]){
            
            if(it == parent) continue;
            
            if(vis[it] == 0){
                
                dfs(it, node, adj, vis, tin, low, bridges);
                
                low[node] = min(low[node], low[it]);
                
                // is it a bridge
                // node -- it
                if(low[it] > tin[node]){
                    bridges.push_back({node , it});
                }
            }
            else{
                low[node] = min(low[node], low[it]);
            }
        }
    }
    
public:
	vector<vector<int>>criticalConnections(int V, vector<int> adj[]){
	    // Code here
	    
	    vector<int> vis(V, 0);
	    int tin[V];
	    int low[V];
	    
	    vector<vector<int>> bridges;
	    dfs(0, -1, adj, vis, tin, low, bridges);
	    
	    for(int i=0; i<bridges.size(); i++){
	        sort(begin(bridges[i]), end(bridges[i]));
	    }
	    
	    sort(begin(bridges), end(bridges));
	    return bridges;
	}
};

//{ Driver Code Starts.

int main(){
	int tc;
    cin >> tc;
    while(tc--){
        int V, E;
        cin >> V >> E;
        vector<int>adj[V];
        for(int i = 0; i < E; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        vector<vector<int>>ans = obj.criticalConnections(V, adj);
        
        for(int i=0;i<ans.size();i++)
            cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
	return 0;
}
// } Driver Code Ends