class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        
        int n = mat.size();
        
        int d1 = 0;
        int d2 = 0;
        
        for(int i=0; i<n; i++){
            
            for(int j=0; j<n; j++){
                
                if(i == j)
                    d1 += mat[i][j];
                
                if(i+j == n-1)
                    d2 += mat[i][j];
            }
        }
        
        return n % 2 == 1 ? d1 + d2 - mat[n/2][n/2] : d1 + d2;
    }
};