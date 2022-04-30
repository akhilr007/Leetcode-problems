class UnionFind{
private:
    vector<int> parent;
    vector<int> rank;
public:
    UnionFind(int size) : rank(size), parent(size){
        for(int i=0; i<size; i++){
            parent[i] = i;
            rank[i] = 0;
        }
    }
    
    int find(int x){
        if(x == parent[x]){
            return x;
        }
        
        return parent[x] =  find(parent[x]);
    }
    
    void unionSet(int x, int y){
        
        int sl1 = find(x);
        int sl2 = find(y);
        
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
        }
    }
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        
        UnionFind uf(s.length());
        
        for(int i=0; i<pairs.size(); i++){
            
            int x = pairs[i][0];
            int y = pairs[i][1];
            
            uf.unionSet(x, y);
        }
        
        unordered_map<int, vector<int>> m;
        
        for(int i=0; i<s.length(); i++){
            m[uf.find(i)].push_back(i);
        }
        
        for(auto i : m){
            string res="";
            
            for(auto j : i.second){
                res += s[j];
            }
            
            sort(res.begin(), res.end());
            
            int k=0;
            for(auto j : i.second){
                s[j] = res[k];
                k++;
            }
        }
        
        return s;
    }
};