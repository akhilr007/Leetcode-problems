// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	void dfs(int src, vector<int> adj[], vector<bool>& vis, stack<int>& st){
	    
	    vis[src] = true;
	    
	    for(int nbr : adj[src]){
	        if(vis[nbr] == false){
	            dfs(nbr, adj, vis, st);
	        }
	    }
	    
	    st.push(src);
	}
	
	void dfs2(int src, vector<int> graph[], vector<bool>& vis){
	    
	    vis[src] = true;
	    
	    for(int nbr : graph[src]){
	        if(vis[nbr] == false){
	            dfs2(nbr, graph, vis);
	        }
	    }
	    
	}
	
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        // 1. random order dfs
        stack<int> st;
        vector<bool> vis(V, false);
        for(int i=0; i<V; i++){
            if(vis[i] == false){
                dfs(i, adj, vis, st);
            }
        }
        
        //2. reverse the edges;
        vector<int> graph[V];
        for(int i=0; i<V; i++){
            vector<int> nbrs = adj[i];
            for(int nbr : nbrs){
                graph[nbr].push_back(i);
            }
        }
        
        // 3. dfs according to stack
        for(int i=0; i<V; i++) vis[i] = false;
        
        int connectedComponents=0;
        while(st.size()>0){
            int src = st.top();
            st.pop();
            if(vis[src] == false){
                dfs2(src, graph, vis);
                connectedComponents++;
            }
        }
        
        return connectedComponents;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends