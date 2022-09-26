class Solution {
    int[] rank = new int[26];
    int[] parent = new int[26];
    
    public int find(int x){
        
        if(parent[x] == x){
            return x;
        }
        
        int temp = find(parent[x]);
        parent[x] = temp;
        return temp;
    }
    
    public void unionSet(int u, int v){
        
        int lx = find(u);
        int ly = find(v);
        
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
    }
    
    public boolean equationsPossible(String[] equations) {
        
        // initialize rank -> 1 and parent -> i
        for(int i=0; i<26; i++){
            rank[i] = 1;
            parent[i] = i;
        }
        
        for(String equation : equations){
            
            if(equation.charAt(1) == '='){
                char ch1 = equation.charAt(0);
                char ch2 = equation.charAt(3);

                int u = ch1 - 'a';
                int v = ch2 - 'a';

                unionSet(u, v);
            }
        }
        
        for(String equation : equations){
            
            if(equation.charAt(1) == '!'){
                char ch1 = equation.charAt(0);
                char ch2 = equation.charAt(3);
                
                int u = ch1 - 'a';
                int v = ch2 - 'a';
                
                if(find(u) == find(v)) return false;
                
            }
        }
        
        return true;
        
    }
}