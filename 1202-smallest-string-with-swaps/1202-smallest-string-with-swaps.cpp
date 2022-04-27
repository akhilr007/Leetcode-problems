class Solution {
public:
    
    int find(int x, vector<int>& parent){
        
        if(x == parent[x]){
            return x;
        }
        
        int sl = find(parent[x], parent);
        parent[x] = sl;
        return sl;
    }
    
    void dsu(int u, int v, vector<int>& parent, vector<int>& rank){
        
        int sl1 = find(u, parent);
        int sl2 = find(v, parent);
        
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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        
        int n=s.size();
        
        vector<int> parent(n);
        vector<int> rank(n, 0);
        
        for(int i=0; i<n; i++){
            parent[i]=i;
        }
        
        for(int i=0; i<pairs.size(); i++){
            int u = pairs[i][0];
            int v = pairs[i][1];
            
            dsu(u, v, parent, rank);
        }
        
        unordered_map<int, vector<int>> m;
        
        // add parent and its child in map
        // suppose 0->3 0 has a parent 3
        // so map will store m[3] -> [0]
        // and in example 2
        // everyone parent will be 2 so
        // m[2] -> [0, 1, 2, 3]
        for(int i=0; i<n; i++){
            m[find(i, parent)].push_back(i);
        }
        
        for(auto i : m){
            string res="";
            for(auto j : i.second){
                res += s[j];
            }
            
            sort(res.begin(), res.end());
            
            int k=0;
            for(auto j: i.second){
                s[j] = res[k];
                k++;
            }
        }
        
        return s;
    }
};