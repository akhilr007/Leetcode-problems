// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    int n=matrix.size();
	    int m=matrix[0].size();
	    
	    for(int i=0; i<n; i++)
	    {
	        for(int j=0; j<m; j++)
	        {
	            if(matrix[i][j] == -1)
	            {
	                matrix[i][j] = INT_MAX;
	            }
	        }
	    }
	    
	    for(int k=0; k<n; k++)
	    {
	        for(int u=0; u<n; u++)
	        {
	            for(int v=0; v<m; v++)
	            {
	                if(u != k && v != k && u != v && matrix[u][k] != INT_MAX && matrix[k][v] != INT_MAX && matrix[u][k] + matrix[k][v] < matrix[u][v])
	                {
	                    matrix[u][v] = matrix[u][k] + matrix[k][v];
	                }
	            }
	        }
	    }
	    
	    for(int i=0; i<n; i++){
	        for(int j=0; j<m; j++){
	            if(matrix[i][j] == INT_MAX){
	                matrix[i][j] = -1;
	            }
	        }
	    }
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends