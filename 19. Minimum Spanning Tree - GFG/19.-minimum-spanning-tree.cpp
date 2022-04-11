// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> graph[])
    {
        vector<bool> visited(V, false);
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        pq.push(make_pair(0, 0));
        
        int cost=0;
        
        while(pq.size()>0){
            
            auto rem = pq.top();
            pq.pop();
            
            int wt = rem.first;
            int v = rem.second;
            
            if(visited[v] == true) continue;
            
            visited[v] = true;
            
            cost += wt;
            
            for(vector<int> edge : graph[v]){
                
                int nbr = edge[0];
                int weight = edge[1];
                
                if(visited[nbr] == false){
                    pq.push({weight, nbr});
                }
            }
        }
        
        return cost;
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
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver nbrCode Ends