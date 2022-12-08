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
    
    int findCircleNum(vector<vector<int>>& graph) {
        
        // create the adjacency list
        int N = graph.size();
        vector<int> adj[N+1];
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(graph[i][j] == 1 && i != j){
                    adj[i+1].push_back(j+1);
                }
            }
        }
        
        for(int i=0; i<=N; i++){
            cout<<i<<"->[";
            for(auto nbr: adj[i]){
                cout<<nbr<<", ";
            }
            cout<<"]";
            cout<<endl;
        }
        cout<<endl;
        vector<bool> vis(N+1, false);
        int count=0;

        for(int i=1; i<=N; i++){
            if(vis[i] == false){
                cout<<i<<endl;
                count++;
                dfs(i, adj, vis);
            }
        }

        return count;
    }
};