class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int count = 0;
        
        map<vector<int>, int> mp;
        
        for(auto row: grid)
            mp[row]++;
        
        for(int c=0; c<n; c++){
            vector<int> col(n);
            for(int r=0; r<n; r++){
                col[r] = grid[r][c];
            }
            
            if(mp.find(col) != mp.end())
                count += mp[col];
        }
        
        return count;
    }
};