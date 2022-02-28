class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        // time complexity -> O(m+n)
        
//         int n=matrix.size();
//         int m=matrix[0].size();
        
//         int j=m-1;
//         int i=0;
        
//         while(i<n && j>=0){
            
//             if(matrix[i][j] == target){
//                 return true;
//             }
            
//             else if(matrix[i][j] > target){
//                 j--;
//             }
//             else if(matrix[i][j] < target){
//                 i++;
//             }
//         }
        
//         return false;
        
        int n=matrix.size();
        int m=matrix[0].size();
        
        int lo=0;
        int hi=n*m-1;
        
        while(lo<=hi){
            
            int mid = lo + (hi-lo)/2;
            
            int r = mid/m;
            int c = mid%m;
            
            if(matrix[r][c] == target) return true;
            else if(matrix[r][c] > target) hi--;
            else lo++;
        }
        
        return false;
    }
};