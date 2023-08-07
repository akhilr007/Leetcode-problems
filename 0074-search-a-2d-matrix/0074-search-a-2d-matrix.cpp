class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int N = matrix.size();
        int M = matrix[0].size();
        
        int l=0;
        int r=(N*M)-1;
        
        while(l<=r){
            
            int mid = (l+r)/2;
            
            if(matrix[mid/M][mid%M] == target)
                return true;
            else if(matrix[mid/M][mid%M] > target){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        
        return false;
    }
};