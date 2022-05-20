class Solution{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix){
        vector<int> ans;

        int top=0, bottom=matrix.size()-1, left=0, right=matrix[0].size()-1;

        int dir=1;

        while(top <= bottom and left <= right){

            if(dir == 1){
                // left to right print
                for(int i=left; i<=right; i++){
                    ans.push_back(matrix[top][i]);
                }
                top++;
                dir = 2;
            }

            else if(dir == 2){

                // top to bottom
                for(int i=top; i<=bottom; i++){
                    ans.push_back(matrix[i][right]);
                }
                right--;
                dir = 3;
            }

            else if(dir == 3){

                // right to left
                for(int i=right; i>=left; i--){
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
                dir = 4;
            }
            
            else if(dir == 4){
                // bottom to up
                for(int i=bottom; i>= top; i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;
                dir = 1;
            }
        }

        return ans;
    }
};