class UnionFind{
private:
    vector<int> parent;
    vector<int> rank;
    int count;
public:
    UnionFind(int size) : parent(size), rank(size){
        count=1;
        for(int i=0; i<size; i++){
            rank[i]=1;
            parent[i]=i;
        }
    }
    
    int getCount(){
        return count;
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
                parent[ly] = lx;
            }
            else if(rank[ly] > rank[lx]){
                parent[lx] = ly;
            }
            else{
                parent[ly] = lx;
                rank[lx]++;
            }
        }
        else{
            count++;
        }
    }
};

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        
        int n = grid.size();
        int dots = n+1;
        
        UnionFind uf(dots*dots);
        
        // merge all boundary of a square
        for(int i=0; i<dots; i++){
            for(int j=0; j<dots; j++){
                if(i==0 || j==0 || i==dots-1 || j==dots-1){
                    
                    int cellno = i*dots + j;
                    
                    if(cellno != 0) uf.unionSet(0, cellno);
                }
            }
        }
        
        for(int i=0; i<grid.size(); i++){
            string s = grid[i];
            for(int j=0; j<s.length(); j++){
                
                if(s[j] == '/'){
                    int c1 = i*dots + j+1;
                    int c2 = (i+1)*dots + j;
                    
                    uf.unionSet(c1, c2);
                    
                }
                else if(s[j] == '\\'){
                    
                    int c1 = i*dots+j;
                    int c2 = (i+1)*dots + j+1;
                    
                    uf.unionSet(c1, c2);
                }
            }
        }
        
        return uf.getCount();
    }
};