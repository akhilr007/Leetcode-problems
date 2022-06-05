class UnionFind{
 private:
    vector<int> rank, parent;
    
public:
    UnionFind(int size) : rank(size), parent(size) {
        for(int i=0; i<size; i++){
            rank[i] = 1;
            parent[i] = i;
        }
    }
    
    int find(int x){
        
        if(parent[x] == x){
            return parent[x];
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
            return false;// cycle present hai
        }
    }
    
};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();
        vector<int> indegree(n+1, -1);
        
        int bl1=-1, bl2=-1; // blacklist1 and blacklist2
        
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            if(indegree[v] == -1){
                indegree[v]=i;
            }
            else{
                bl1 = i;
                bl2 = indegree[v];
            }
        }
        
        UnionFind uf(n+1);
        
        for(int i=0; i<edges.size(); i++){
            
            if(i == bl1) continue; // probable answer hatane ke baad be cycle milta h nai
            
            int u = edges[i][0];
            int v = edges[i][1];
            
            if(uf.unionSet(u, v) == false){
                // cycle present hai
                if(bl1 == -1){
                    // kisi ke pass be two parent nai h
                    return edges[i];
                }
                else{
                    return edges[bl2];
                }
            }
        }
        
        return edges[bl1];
        
    }
};