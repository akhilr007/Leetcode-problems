class Solution {
public:
    static bool comp(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b){
        return a.first < b.first;
    }
    
    int find(int x, vector<int>& parent){
        
        if(x == parent[x]){
            return x;
        }
        
        int sl = find(parent[x], parent);
        parent[x] = sl;
        return sl;
    }
    
    bool dsu(int u, int v, vector<int>& parent, vector<int>& rank){
        
        int sl1 = find(u, parent);
        int sl2 = find(v, parent);
        
        if(sl1 != sl2){
            cout <<u << " "<<v<<endl;
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
            return true;
        }
        else{
            return false;
        }
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        // using kruskal
        vector<pair<int, pair<int, int>>> dist;
        // to store cost of all points
        // like i->j where i is [0, 0] and j is [2, 2]
        
        int n=points.size();
        
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                
                int cost=abs(points[j][0] - points[i][0]) + abs(points[j][1] - points[i][1]);
                dist.push_back({cost, {i, j}});
            }
        }
        
        // sort the edges by cost
        sort(dist.begin(), dist.end(), comp);
        
        // for disjoin set union make parent and rank
        vector<int> parent(n), rank(n, 0);
        for(int i=0; i<n; i++){
            parent[i]=i;
        }
        
        int minCost=0;
        for(int i=0; i<dist.size(); i++){
            
            int u = dist[i].second.first;
            int v = dist[i].second.second;
            int wt = dist[i].first;
            
            if(dsu(u, v, parent, rank) == true){
                minCost += wt;
            }
        }
        
        return minCost;
        
    }
};