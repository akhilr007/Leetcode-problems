class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> res(n, vector<int>(n, 0));
        
        int top=0;
        int left=0;
        int bottom=n-1;
        int right=n-1;
        
        int dir=1;
        
        int val=1;
        
        while(top <= bottom && left <= right){
            
            // left to right
            if(dir == 1){
                
                for(int i=left; i<=right; i++){
                    
                    res[top][i] = val;
                    val++;
                }
                
                top++;
                dir=2;
            }
            // top to bottom
            else if(dir == 2){
                
                for(int i=top; i<=bottom; i++){
                    res[i][right] = val;
                    val++;
                }
                
                right--;
                dir=3;
            }
            
            // right to left
            else if(dir == 3){
                
                for(int i=right; i>=left; i--){
                    
                    res[bottom][i] = val;
                    val++;
                }
                
                bottom--;
                dir=4;
            }
            //bottom to top
            else if(dir == 4){
                
                for(int i=bottom; i>=top; i--){
                    
                    res[i][left] = val;
                    val++;
                }
                
                left++;
                dir=1;
            }
        }
        
        return res;
        
    }
};