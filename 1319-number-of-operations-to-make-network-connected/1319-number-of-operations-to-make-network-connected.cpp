class UnionFind{   
public:
    vector<int> size, parent;
    UnionFind(int n){
        size.resize(n, 1);
        parent.resize(n);
        
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
    }
    
    int findUltimateParent(int x){
        
        if(x == parent[x])
            return x;
        
        return parent[x] = findUltimateParent(parent[x]);
    }
    
    void unionBySize(int x, int y){
        
        int parentX = findUltimateParent(x);
        int parentY = findUltimateParent(y);
        
        if(parentX == parentY)
            return;
        
        if(size[parentX] < size[parentY]){
            parent[parentX] = parentY;
            size[parentY] += size[parentX];
        }
        else{
            parent[parentY] = parentX;
            size[parentX] += size[parentY];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        UnionFind uf(n);
        
        int countExtraEdges=0;
        for(auto &it : connections){
            
            int u = it[0];
            int v = it[1];
            
            if(uf.findUltimateParent(u) == uf.findUltimateParent(v)){
                countExtraEdges++;
            }
            else{
                uf.unionBySize(u, v);
            }
        }
        
        int numberOfComponents=0;
        for(int i=0; i<n; i++){
            if(uf.parent[i] == i)
                numberOfComponents++;
        }
        
        int edgesRequiredToMakeConnection = numberOfComponents - 1;
        if(countExtraEdges >= edgesRequiredToMakeConnection)
            return edgesRequiredToMakeConnection;
        
        return -1;
    }
};