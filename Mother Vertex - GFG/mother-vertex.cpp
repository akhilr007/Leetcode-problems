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
    
    void dfs(int src, vector<int> adj[], vector<bool>& vis, int& count){
        
        vis[src] = true;
        count++;
        
        for(int nbr : adj[src]){
            if(vis[nbr] == false){
                dfs(nbr, adj, vis, count);
            }
        }
        
    }
    
    //Function to find a Mother Vertex in the Graph.
	int findMotherVertex(int V, vector<int>adj[])
	{
	    vector<bool> vis(V, false);
	    stack<int> st;
	    
	    for(int i=0; i<V; i++){
	        if(vis[i] == false){
	            dfs(i, adj, vis, st);
	        }
	    }
	    
	    int probableMotherVertex = st.top();
	    int count=0;
	    
	    for(int i=0; i<V; i++) vis[i]=false;
	    
	    dfs(probableMotherVertex, adj, vis, count);
	    
	    if(count == V){
	        return probableMotherVertex;
	    }
	    return -1;
	}

};

// { Driver Code Starts.
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
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends