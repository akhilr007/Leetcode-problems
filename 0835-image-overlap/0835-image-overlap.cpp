class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        
        int len=A.size();
        vector<pair<int, int>> p1, p2;
        for(int i=0; i<len; i++){
            for(int j=0; j<len; j++){
                if(A[i][j] == 1) p1.push_back({i, j});
                
                if(B[i][j] == 1) p2.push_back({i, j});
                
            }
        }
        
        map<pair<int, int>, int> m;
        int ans=0;
        for(auto i: p1){
            for(auto j: p2){
                
                int x = i.first - j.first;
                int y = i.second - j.second;
                
                m[{x, y}]++;
                ans = max(ans, m[{x, y}]);
            }
        }
        
        return ans;
    }
};