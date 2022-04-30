class UnionFind{
private:
    vector<int> parent;
    vector<int> rank;
    int count;
    
public:
    
    UnionFind(int size) : parent(size), rank(size), count(size){
        for(int i=0; i<size; i++){
            rank[i]=0;
            parent[i] = i;
        }
    }
    
    int find(int x){
        if(x == parent[x]){
            return x;
        }
        
        return parent[x] = find(parent[x]);
    }
    
    void unionSet(int u, int v){
        
        int sl1 = find(u);
        int sl2 = find(v);
        
        if(sl1 != sl2){
            
            if(rank[sl1] < rank[sl2]){
                parent[sl1] = parent[sl2];
            }
            else if(rank[sl2] < rank[sl1]){
                parent[sl2] = parent[sl1];
            }
            else{
                parent[sl1] = parent[sl2];
                rank[sl2]++;
            }
            
            count--;
        }
    }
    
    int getCount(){
        return count;
    }
    
    
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        if(isConnected.size() == 0) return 0;
        
        int n = isConnected.size();
        
        UnionFind uf(n);
        
        for(int i=0; i<isConnected.size(); i++){
            for(int j=i+1; j<isConnected.size(); j++){
                
                if(isConnected[i][j] == 1){
                    uf.unionSet(i, j);
                }
            }
        }
        
        return uf.getCount();
    }
};