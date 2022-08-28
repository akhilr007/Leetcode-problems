class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        
        int rows = mat.size();
        int cols = mat[0].size();
        
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> m; // min heap> m;
        
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                
                int diagonalKey = i-j;
                m[diagonalKey].push(mat[i][j]);
                
            }
        }
        
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                
                int diagonalKey = i-j;
                auto pq = m[diagonalKey];
                
                mat[i][j] = pq.top();
                pq.pop();
                
                m[diagonalKey] = pq;
            }
        }
        
        return mat;
    }
};