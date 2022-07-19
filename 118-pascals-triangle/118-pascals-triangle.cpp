class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> ans;
        
        for(int i=0; i<numRows; i++){
            
            vector<int> col;
            
            for(int j=0; j<=i; j++){
                
                if(j == 0 || j == i){
                    col.push_back(1);
                }
                else{
                    int val = ans[i-1][j-1] + ans[i-1][j];
                    col.push_back(val);
                }
                
            }
            
            ans.push_back(col);
        }
        
        return ans;
    }
};