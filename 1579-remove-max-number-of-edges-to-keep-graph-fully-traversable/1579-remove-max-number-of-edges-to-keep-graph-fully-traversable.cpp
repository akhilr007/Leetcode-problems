class UnionFind {
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
    
    bool unionBySize(int u, int v){
        
        int parentU = findParent(u);
        int parentV = findParent(v);
        
        if(parentU == parentV)
            return false;
        
        if(size[parentU] < size[parentV]){
            parent[parentU] = parentV;
            size[parentV] += size[parentU];
        }
        else{
            parent[parentV] = parentU;
            size[parentU] += size[parentV];
        }
        
        return true;
    }
};


class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        
        UnionFind alice(n+1);
        UnionFind bob(n+1);
        
        sort(begin(edges), end(edges), [&](auto const &v1, auto const& v2){
            return v1[0] > v2[0];
        });
        
        int alice_edges = 0;
        int bob_edges = 0;
        
        int remove_edges = 0;
        
        for(auto& e: edges)
        {
            if(e[0] == 3){
                
                bool a = alice.unionBySize(e[1], e[2]);
                bool b = bob.unionBySize(e[1], e[2]);
                
                if(a == true)
                    alice_edges ++;
                
                if(b == true)
                    bob_edges ++;
                
                if(a == false && b == false)
                    remove_edges ++;
            }
            else if(e[0] == 1){
                
                bool a = alice.unionBySize(e[1], e[2]);
                
                if(a == true)
                    alice_edges ++;
                else
                    remove_edges ++;
            }
            else if(e[0] == 2){
                
                bool b = bob.unionBySize(e[1], e[2]);
                
                if(b == true){
                    bob_edges ++;
                }
                else
                    remove_edges++;
            }
        }
        
        if(alice_edges != n-1 || bob_edges != n-1)
            return -1;
        
        return remove_edges;
    }
};