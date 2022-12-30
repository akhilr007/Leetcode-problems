//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    private:
    void dfs(int node, vector<int> adj[], vector<int>& vis, stack<int>& st){
        
        vis[node] = 1;
        for(auto adjNode: adj[node]){
            if(!vis[adjNode]){
                dfs(adjNode, adj, vis, st);
            }
        }
        
        st.push(node);
    }
    
    void dfs2(int node, vector<int> adjT[], vector<int>& vis){
        
        vis[node] = 1;
        for(auto adjNode: adjT[node]){
            if(!vis[adjNode]){
                dfs2(adjNode, adjT, vis);
            }
        }
    }
    
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        vector<int> vis(V, 0);
        stack<int> st;
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i, adj, vis, st);
            }
        }
        
        vector<int> adjT[V];
        for(int i=0; i<V; i++){
            vis[i] = 0;
            for(auto it: adj[i]){
                // i-> it
                // it -> i
                adjT[it].push_back(i);
            }
        }
        
        int scc=0;
        while(!st.empty()){
            
            int node = st.top();
            st.pop();
            
            if(!vis[node]){
                scc++;
                dfs2(node, adjT, vis);
            }
        }
        
        return scc;
    }
};

//{ Driver Code Starts.


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