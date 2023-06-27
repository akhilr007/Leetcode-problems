class Solution {
public:
    vector<vector<int>> brute(vector<int>& a, vector<int>& b, int k){
        
        int n = a.size();
        int m = b.size();
        
        vector<vector<int>> sums;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                vector<int> temp = {a[i] + b[j], a[i], b[j]};
                sums.push_back(temp);
            }
        }
        
        sort(begin(sums), end(sums));
        
        vector<vector<int>> result;
        
        for(int i=0; i<min(k, (int)sums.size()); i++){
            vector<int> temp = {sums[i][1], sums[i][2]};
            result.push_back(temp);
        }
        return result;
    }
    
    vector<vector<int>> kSmallestPairs(vector<int>& a, vector<int>& b, int k) {
        
        int n = a.size();
        int m = b.size();
        
        priority_queue<pair<int, pair<int, int>> , vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        
        set<pair<int, int>> visited;
        
        pq.push({a[0]+b[0], {0, 0}});
        
        vector<vector<int>> result;
        
        while(k-- and !pq.empty()){
            
            auto top = pq.top(); pq.pop();
            
            int i = top.second.first;
            int j = top.second.second;
            result.push_back({a[i], b[j]});
            
//             cout << i <<" " << j << endl;
//             cout << i+1 << " " << j << " / " << i << " " << j+1 << endl; 
            
            if(i+1<n and visited.find({i+1, j}) == visited.end()){
                pq.push({a[i+1]+b[j], {i+1, j}});
                visited.insert({i+1, j});
            }
            
            if(j+1<m and visited.find({i, j+1}) == visited.end()){
                pq.push({a[i]+b[j+1], {i, j+1}});
                visited.insert({i, j+1});
            }
        }
        return result;
    }
};