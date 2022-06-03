// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    void dfs(vector<int> adj[], int src, int par, vector<bool>& vis, vector<bool>& ap,
    vector<int>& disc, vector<int>& low, int& t, int& osc){

        disc[src] = low[src] = t;
        t++;

        vis[src] = true;

        for(int nbr : adj[src]){

            if(par == nbr){
                continue;
            }
            else if(vis[nbr] == true){
                low[src] = min(low[src], disc[nbr]);
            }
            else{
                dfs(adj, nbr, src, vis, ap, disc, low, t, osc);
                low[src] = min(low[src], low[nbr]);

                if(par == -1){
                    osc++;
                    if(osc > 1){
                        ap[src] = true;
                    }
                }
                else if(low[nbr] >= disc[src]){
                    ap[src] = true;
                }
            }
        }
    }

    vector<int> articulationPoints(int v, vector<int> adj[]){

        vector<bool> ap(v, false);
        vector<bool> vis(v, false);
        vector<int> disc(v, 0), low(v, 0);
        int t=0;
        int par=-1; // parent
        int osc=0; // original source count
        
        for(int i=0; i<v; i++){
            if(vis[i]==false){
                par=-1;
                t=0;
                osc=0;
                dfs(adj, i, par, vis, ap, disc, low, t, osc);
            }
        }
        

        vector<int> res;
        for(int i=0; i<v; i++){
            if(ap[i]==true){
                res.push_back(i);
            }
        }

        if(res.size()==0){
            res.push_back(-1);
            return res;
        }

        return res;
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
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends