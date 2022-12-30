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
private:
    bool isValid(int r, int c, int n){
        return r>=0 and r<n and c>=0 and c<n;
    }
    
public:
    int largestIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        UnionFind uf(n*n);
        
        int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        
        // step1 -> connect all the components
        for(int row=0; row<n; row++){
            for(int col=0; col<n; col++){
                
                if(grid[row][col] == 0) continue;
                
                for(int d=0; d<4; d++){
                    
                    int new_row = row + dir[d][0];
                    int new_col = col + dir[d][1];
                    
                    if(isValid(new_row, new_col, n) && grid[new_row][new_col] == 1){
                        
                        int nodeNo = row *n + col;
                        int adjNodeNo = new_row * n + new_col;
                        
                        // connect all the 1s to make a component
                        uf.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }
        
        int mx=0;
        // step2 -> connect all zero to find which makes big component
        for(int row=0; row<n; row++){
            for(int col=0; col<n; col++){
                
                if(grid[row][col] == 1) continue;
                set<int> components; // to store all the parent components
                for(int d=0; d<4; d++){
                    int new_row = row + dir[d][0];
                    int new_col = col + dir[d][1];
                    
                    if(isValid(new_row, new_col, n)){
                        if(grid[new_row][new_col] == 1){
                            
                            int adjNodeNo = (new_row * n) + new_col;
                            int findComponentParent = uf.findUltimateParent(adjNodeNo);
                            components.insert(findComponentParent);
                        }
                    }
                }
                
                int sizeTotal=0;
                for(auto it: components){
                    sizeTotal += uf.size[it];
                }
                mx = max(mx, sizeTotal + 1); // 1 for self node
            }
        }
        // if all the cells are 1 then
        for(int cellNo=0; cellNo<n*n; cellNo++){
            mx = max(mx, uf.size[uf.findUltimateParent(cellNo)]);
        }
        
        return mx;
    }
};