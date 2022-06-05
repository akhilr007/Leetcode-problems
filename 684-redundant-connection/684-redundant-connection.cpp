class UnionFind{
private: 
    vector<int> rank, parent;
public:
    UnionFind(int size) : rank(size), parent(size){
        for(int i=0; i<size; i++){
            rank[i]=1;
            parent[i]=i;
        }
    }
    
    int find(int x){
        if(parent[x] == x){
            return x;
        }
        
        int temp = find(parent[x]);
        parent[x] = temp;
        return temp;
    }
    
    bool unionSet(int x, int y){
        
        int lx = find(x);
        int ly = find(y);
        
        if(lx != ly){
            
            if(rank[lx] > rank[ly]){
                parent[ly] = lx;
            }
            else if(rank[lx] < rank[ly]){
                parent[lx] = ly;
            }
            else{
                parent[ly] = lx;
                rank[lx]++;
            }
            
            return true;
        }
        else{
            return false;
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();
        UnionFind uf(n+1);
        
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            
            if(uf.unionSet(u,v)==false){
                return edge;
            }
        }
        
        return vector<int>();
    }
};