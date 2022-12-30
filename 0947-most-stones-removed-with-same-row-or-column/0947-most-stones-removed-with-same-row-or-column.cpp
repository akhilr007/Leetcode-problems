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

    int findUltimateParent(int node){

        if(node == parent[node]){
            return node;
        }

        return parent[node] = findUltimateParent(parent[node]);
    }

    void unionBySize(int u, int v){

        int parentU = findUltimateParent(u);
        int parentV = findUltimateParent(v);

        if(parentU == parentV) return;

        if(size[parentU] < size[parentV]){
            parent[parentU] = parentV;
            size[parentV] += size[parentU];
        }
        else{
            parent[parentV] = parentU;
            size[parentU] += size[parentV];
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        
        int n = stones.size(); // no of stones
        
        int maxRow = 0, maxCol=0;
        for(auto it: stones){
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
        
        UnionFind uf(maxRow + maxCol + 2);
        // for every row we will have 0 -> maxrow
        // for every col we will have col + maxrow + 1, e.g->col=2, 2 + (4+1) = 7
        
        unordered_map<int, int> stoneNode;
        for(auto it: stones){
            int nodeRow = it[0];
            int nodeCol = it[1] + (maxRow + 1);
            
            uf.unionBySize(nodeRow, nodeCol);
            
            stoneNode[nodeRow] = 1;
            stoneNode[nodeCol] = 1;
        }
        
        int comps=0; // no of components
        for(auto it: stoneNode){
            if(uf.findUltimateParent(it.first) == it.first) comps++;
        }
        
        return n - comps;
    }
};