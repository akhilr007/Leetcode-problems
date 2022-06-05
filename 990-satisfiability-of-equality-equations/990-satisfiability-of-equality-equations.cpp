class UnionFind{
private:
    vector<int> rank, parent;
public:
    UnionFind(int size): rank(size), parent(size){
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
    
    void unionSet(int x, int y){
        
        int lx = find(x);
        int ly = find(y);
        
        if(lx != ly){
            if(rank[lx] > rank[ly]){
                parent[ly]=lx;
            }
            else if(rank[lx] < rank[ly]){
                parent[lx] = ly;
            }
            else{
                parent[ly] = lx;
                rank[lx]++;
            }
        }
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        
        UnionFind uf(26); 
        
        for(auto s : equations){
            if(s[1] == '='){
                int u = s[0]-'a';
                int v = s[3]-'a';
                uf.unionSet(u, v);
            }
        }
        
       for(auto s : equations){
            if(s[1] == '!'){
                int u = s[0]-'a';
                int v = s[3]-'a';
                
                if(uf.find(u) == uf.find(v)){
                    return false;
                }
            }
        }
        
        return true;
    }
};