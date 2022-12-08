//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  void dfs(int node, vector<int> adj[], vector<bool>& vis){

        vis[node] = true;

        for(auto& nbr: adj[node]){
            if(vis[nbr] == false){
                dfs(nbr, adj, vis);
            }
        }
    }
    int numProvinces(vector<vector<int>> graph, int V) {
        // code here
        // create the adjacency list
        int N = graph.size();
        vector<int> adj[N];
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(graph[i][j] == 1 && i != j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        

        vector<bool> vis(N, false);
        int count=0;

        for(int i=0; i<N; i++){
            if(vis[i] == false){
                // cout<<i<<endl;
                count++;
                dfs(i, adj, vis);
            }
        }

        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends