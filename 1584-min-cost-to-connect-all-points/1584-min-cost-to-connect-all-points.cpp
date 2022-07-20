class UnionFind{
private:
    vector<int> rank, parent;
public:
    UnionFind(int size) : rank(size),  parent(size){
        for(int i=0; i<size; i++){
            rank[i] = 0;
            parent[i] = i;
        }
    }
    
    int find(int x){
        
        if(parent[x] == x) return x;
        
        int temp = find(parent[x]);
        parent[x] = temp;
        return temp;
    }
    
    bool unionSet(int x, int y){
        
        int slx = find(x);
        int sly = find(y);
        
        if(slx != sly){
            if(rank[slx] > rank[sly]){
                parent[sly] = slx;
            }
            else if(rank[sly] > rank[slx]){
                parent[slx] = sly;
            }
            else{
                parent[sly] = slx;
                rank[slx]++;
            }
            
            return true;
        }
        else{
            return false;
        }
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n = points.size();
        vector<pair<int, pair<int, int>> > dist;
        
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                
                int cost = abs(x1-x2) + abs(y1-y2);
                dist.push_back({cost, {i, j}});
            }
        }
        
        sort(dist.begin(), dist.end());
        
        UnionFind uf(n);
        int minCost=0;
        
        for(int i=0; i<dist.size(); i++){
            
            int u = dist[i].second.first;
            int v = dist[i].second.second;
            int wt = dist[i].first;
            
            if(uf.unionSet(u, v)){
                minCost += wt;
            }
        }
        
        return minCost;
    }
};