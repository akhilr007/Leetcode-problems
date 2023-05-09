class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        int top=0;
        int left=0;
        int bottom = n-1;
        int right = m-1;
        
        int dir = 0;
        
        vector<int> result;
        
        while(top <= bottom && left <= right){
            
            // left to right
            if(dir == 0){
                for(int i=left; i<=right; i++){
                    result.push_back(matrix[top][i]);
                }
                
                top++;
                dir = 1;
            }
            
            else if(dir == 1){
                for(int i=top; i<=bottom; i++){
                    result.push_back(matrix[i][right]);
                }
                right--;
                dir = 2;
            }
            
            else if(dir == 2){
                for(int i=right; i>=left; i--){
                    result.push_back(matrix[bottom][i]);
                }
                
                bottom--;
                dir = 3;
            }
            else{
                for(int i=bottom; i>=top; i--){
                    result.push_back(matrix[i][left]);
                }
                
                left++;
                dir = 0;
            }
        }
        return result;
    }
};