// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	int flag=0;
    //Function to find if the given edge is a bridge in graph.
    void dfs(vector<int> adj[], int src, int par, vector<bool>& vis,
    vector<int>& disc, vector<int>& low, int& t, int c, int d){
        
        disc[src]=low[src]=t;
        t++;
        
        vis[src]=true;
        
        for(int nbr : adj[src]){
            if(par == nbr) continue;
            else if(vis[nbr] == true){
                low[src] = min(low[src], disc[nbr]);
            }
            else{
                dfs(adj, nbr, src, vis, disc, low, t, c, d);
                low[src] = min(low[src], low[nbr]);
                
                if(low[nbr] > disc[src]){
                    //cout<<nbr<<" "<<src<<endl;
                    if((nbr == c && src == d) || (nbr == d && src == c)){
                        flag=1;
                        break;
                    }
                }
            }
        }
    }
    
    int isBridge(int v, vector<int> adj[], int c, int d) 
    {
        vector<bool> vis(v, false);
        vector<int> disc(v, 0), low(v, 0);
        int t=0;
        int par=-1;
        
        for(int i=0; i<v; i++){
            if(vis[i] == false){
                t=0;
                par=-1;
                dfs(adj, i, par, vis, disc, low, t, c, d);
            }
        }
        return flag;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

  // } Driver Code Ends