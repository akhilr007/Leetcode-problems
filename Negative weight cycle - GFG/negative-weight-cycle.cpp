// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    
	    vector<int> path(n, INT_MAX);
	    path[0]=0;
	    
	    for(int it=0; it<n; it++) // v-1 edges
	    {
	        for(int i=0; i<edges.size(); i++) // edges
	        {
	            int u = edges[i][0];
	            int v = edges[i][1];
	            int wt = edges[i][2];
	            
	            if(path[u] != INT_MAX && path[u] + wt < path[v]){
	                path[v] = path[u] + wt;
	            }
	        }
	    }
	    
	    for(int i=0; i<edges.size(); i++){
	        
	        int u = edges[i][0];
	        int v = edges[i][1];
	        int wt = edges[i][2];
	        
	        if(path[u] != INT_MAX && path[u] + wt < path[v]){
	            return 1;
	        }
	    }
	    
	    return 0;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends