//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    typedef pair<int, pair<int, int>> p;
    int shortestDistance(int N, int M, vector<vector<int>>& A, int X, int Y) {
        
        if(A[0][0] == 0) return -1;

        vector<vector<int>> dist(N, vector<int> (M, 1e9)); 

        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({0, {0, 0}}); // {distance, {row, col}}

        dist[0][0] = 0;

        vector<vector<int>> delta = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

        while(!pq.empty()){

            int dis = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            if(row == X && col == Y) return dis;

            for(int d=0; d<4; d++){
                int nrow = row + delta[d][0];
                int ncol = col + delta[d][1];

                if(nrow >= 0 && ncol >= 0 && nrow < N && ncol < M && A[nrow][ncol] == 1){

                    if(dis + 1 < dist[nrow][ncol]){
                        dist[nrow][ncol] = dis + 1;
                        pq.push({ dist[nrow][ncol], {nrow, ncol}});
                    }
                }
            }
        }

        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends