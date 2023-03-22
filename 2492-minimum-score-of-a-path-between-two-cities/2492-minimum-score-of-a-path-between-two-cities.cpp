// TIME COMPLEXITY -> O(V+E)
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        
      // creating an adjacency list
      vector<pair<int, int>> adj[n+1]; // 1-based indexing

      for(auto& road: roads){

        int src = road[0];
        int nbr = road[1];
        int dist = road[2];

        adj[src].push_back({nbr, dist});
        adj[nbr].push_back({src, dist});
      }

      int minimumScore=INT_MAX;
      // implementing BFS

      queue<int> q;
      q.push(1); // src node -> 1

      vector<int> visited(n+1, 0); // visited list

      while(!q.empty()){

        int size = q.size();
        while(size--){

          int node = q.front();
          q.pop();

          for(auto& adjNode: adj[node]){

            int nbr = adjNode.first;
            int dist = adjNode.second;

            minimumScore = min(minimumScore, dist);
            if(visited[nbr] == 0){
              q.push(nbr);
              visited[nbr] = 1;
            }
          }
        }
      }

      return minimumScore;
    }
};