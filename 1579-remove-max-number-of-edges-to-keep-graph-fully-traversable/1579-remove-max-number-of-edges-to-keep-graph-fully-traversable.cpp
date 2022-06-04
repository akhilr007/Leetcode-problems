class Solution {
public:
    static bool sortByType(const vector<int>& a, vector<int>& b){
        return a[0]>b[0];
    }
    
    int find(int x, vector<int>& parent){
        if(parent[x] == x){
            return x;
        }
        
        int temp = find(parent[x], parent);
        parent[x] = temp;
        return temp;
    }
    
    bool unionSet(int x, int y, vector<int>&rank, vector<int>& parent){
        
        int lx = find(x, parent);
        int ly = find(y, parent);
        
        if(lx != ly){
            
            if(rank[lx] > rank[ly]){
                parent[ly]=lx;
            }
            else if(rank[ly] > rank[lx]){
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
    
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        
        sort(edges.begin(), edges.end(), sortByType);
        
        vector<int> rankA(n+1,0), rankB(n+1,0), parentA(n+1,0), parentB(n+1,0);
        for(int i=1; i<=n; i++){
            rankA[i]=rankB[i]=1;
            parentA[i] = parentB[i]=i;
        }
        
        int mergeA=1;
        int mergeB=1;
        
        int removeEdges=0;
        
        for(auto e : edges){
            
            if(e[0] == 3){
                //both alice and bob
                bool tempA = unionSet(e[1], e[2], rankA, parentA);
                bool tempB = unionSet(e[1], e[2], rankB, parentB);
                
                if(tempA == true){
                    mergeA++;
                }
                if(tempB == true){
                    mergeB++;
                }
                
                if(tempA == false && tempB == false){
                    removeEdges++;
                }
            }
            else if(e[0] == 1){
                // alice
                bool tempA = unionSet(e[1], e[2], rankA, parentA);
                if(tempA == true){
                    mergeA++;
                }
                else{
                    removeEdges++;
                }
            }
            else{
                bool tempB = unionSet(e[1], e[2], rankB, parentB);
                if(tempB == true){
                    mergeB++;
                }
                else{
                    removeEdges++;
                }
            }
        }
        
        if(mergeA != n || mergeB != n) return -1;
        
        return removeEdges;
        
        
    }
};