class UnionFind{
private:
    vector<int> parent, size;
public:
    UnionFind(int n){
        parent.resize(n);
        size.resize(n);
        
        for(int i=0; i<n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    int findParent(int x){
        
        if(parent[x] == x)
            return x;
        
        return parent[x] = findParent(parent[x]);
    }
    
    void unionBySize(int u, int v){
        
        int parentU = findParent(u);
        int parentV = findParent(v);
        
        if(parentU == parentV)
            return;
        
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
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        
        UnionFind uf(n);
        
        for(int i=0; i<queries.size(); i++){
            queries[i].push_back(i);
        }
        
        auto lambda = [&](vector<int>& v1, vector<int>& v2){
            return v1[2] < v2[2];
        };
        sort(begin(edgeList), end(edgeList), lambda);
        sort(begin(queries), end(queries), lambda);
        
        int j=0; // pointing to edges
        
        vector<bool> result(queries.size());
        
        for(int i=0; i<queries.size(); i++){
            
            vector<int> query = queries[i];
            int u = query[0];
            int v = query[1];
            int limit = query[2];
            int index = query[3];
            
            while(j < edgeList.size() && edgeList[j][2] < limit){
                
                uf.unionBySize(edgeList[j][0], edgeList[j][1]);
                j++;
            }
            
            if(uf.findParent(u) == uf.findParent(v)){
                result[index] = true;
            }
            else{
                result[index] = false;
            }
        }
        
        return result;
    }
};