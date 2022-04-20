class Solution {
public:
    int find(int x, vector<int>& parent){
        
        if(parent[x] == x){
            return x;
        }
        
        int sl = find(parent[x], parent);
        parent[x] = sl;
        return sl;
    }
    
    void dsu(int v1, int v2, vector<int>& parent, vector<int>& rank, vector<int>& ans){
        
        int sl1 = find(v1, parent);
        int sl2 = find(v2, parent);
        
        if(sl1 != sl2){
            
            if(rank[sl1] < rank[sl2]){
                parent[sl1] = sl2;
            }
            else if(rank[sl2] < rank[sl1]){
                parent[sl2] = sl1;
            }
            else{
                parent[sl1] = sl2;
                rank[sl2]++;
            }
        }
        
        else{
            ans.push_back(v1);
            ans.push_back(v2);
        }
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();
        vector<int> ans;
        
        vector<int> parent(n+1), rank(n+1, 0);
        for(int i=1; i<n+1; i++){
            parent[i]=i;
        }
        
        for(int i=0; i<edges.size(); i++){
            
            int v1 = edges[i][0];
            int v2 = edges[i][1];
            
            dsu(v1, v2, parent, rank, ans);
        }
        
        return ans;
    }
};