class Solution {
public:
    int nCr(int n, int r){
        
        long long ans = 1;
        for(int i=0; i<r; i++){
            ans = ans * (n - i); 
            ans = ans / (i+1);
        }
        
        return ans;
    }
    
    vector<int> generateRow(int row){
        
        long long ans=1;
        
        vector<int> rowData;
        rowData.push_back(1);
        
        for(int col=1; col<row; col++){
            
            ans = ans * (row - col);
            ans = ans / col;
            
            rowData.push_back(ans);
        }
        
        return rowData;
    }
    
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> result;
        
        for(int row=1; row<=numRows; row++){
            result.push_back(generateRow(row));
        }
        return result;
    }
};