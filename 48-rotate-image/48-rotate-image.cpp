class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        for(int c=0; c<matrix[0].size(); c++){
            int l=0;
            int r=matrix.size()-1;
            while(l<r){
                swap(matrix[l][c], matrix[r][c]);
                l++;
                r--;
            }
            
        }
        
        for(int r=0; r<matrix.size(); r++){
            for(int c=r+1; c<matrix[0].size(); c++){
                swap(matrix[r][c], matrix[c][r]);   
            }
        }
    }
};