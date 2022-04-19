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
    
    void DSU(char op1, char op2, vector<int>& parent, vector<int>& rank){
        
        int v1 = op1 - 'a';
        int v2 = op2 - 'a';
        
        int sl1 =find(v1, parent);
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
    }
    
    bool equationsPossible(vector<string>& equations) {
        
        vector<int> parent(26, 0), rank(26, 0);
        
        for(int i=0; i<26; i++){
            parent[i]=i;
        }
        
        // create DSU with equality strings
        for(int i=0; i<equations.size(); i++){
            
            string eqn = equations[i];
            
            if(equations[i][1] == '='){
                
                char op1 = equations[i][0];
                char op2 = equations[i][3];
                
                DSU(op1, op2, parent, rank);
            }
        }
        
        // verification with inequality strings
        for(int i=0; i<equations.size(); i++){
            
            if(equations[i][1] == '!'){
                
                char op1 = equations[i][0];
                char op2 = equations[i][3];
                
                if(find(op1-'a', parent) == find(op2-'a', parent)){
                    return false;
                }
            }
        }
        
        return true;
    }
};