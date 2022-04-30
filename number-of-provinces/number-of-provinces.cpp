class Solution {
public:
    int find(int x, vector<int>& parent){
        
        if(parent[x] == x){
            return x;
        }
        
        return parent[x] = find(parent[x], parent);
    }
    
    void Union(int u, int v, vector<int>& parent, vector<int>& rank, int& provincesConnected){
        
        int rootU = find(u, parent);
        int rootV = find(v, parent);
        
        if(rootU != rootV){
            
            if(rank[rootU] < rank[rootV]){
                parent[rootU] = parent[rootV];
            }
            else if(rank[rootU] < rank[rootV]){
                parent[rootV] = parent[rootU];
            }
            else{
                parent[rootU] = parent[rootV];
                rank[rootV]++;
            }
            
            provincesConnected--;
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        int m = isConnected[0].size();
        
        vector<int> parent(n), rank(n, 0);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
        
        int provincesConnected=n;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<m; j++){
                if(isConnected[i][j] == 1){
                    Union(i, j, parent, rank, provincesConnected);
                }
            }
        }
        
        return provincesConnected;
    }
};