class NumMatrix {
public:
    vector<vector<int>> cum_matrix;
    NumMatrix(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        cum_matrix.resize(n, vector<int> (m, 0));
        
        cum_matrix[0][0] = matrix[0][0];
        // for 1st row -> cumulative sum
        for(int col_ind=1; col_ind<m; col_ind++){
            cum_matrix[0][col_ind] = cum_matrix[0][col_ind-1] + matrix[0][col_ind];
        }
        
        // for 1st col -> cumulative sum
        for(int row_ind=1; row_ind<n; row_ind++){
            cum_matrix[row_ind][0] = cum_matrix[row_ind-1][0] + matrix[row_ind][0];
        }
        
        for(int row_ind=1; row_ind<n; row_ind++){
            for(int col_ind=1; col_ind<m; col_ind++){
                
                cum_matrix[row_ind][col_ind] = matrix[row_ind][col_ind] + cum_matrix[row_ind][col_ind-1] + cum_matrix[row_ind-1][col_ind] - cum_matrix[row_ind-1][col_ind-1];
            }
        }
    }
    
    int sumRegion(int start_row, int start_col, int end_row, int end_col) {
        
        if(start_row == 0 and start_col == 0){
            return cum_matrix[end_row][end_col];
        }
        else if(start_row == 0){
            return cum_matrix[end_row][end_col] - cum_matrix[end_row][start_col-1];
        }
        else if(start_col == 0){
            return cum_matrix[end_row][end_col] - cum_matrix[start_row-1][end_col];
        }
        else{
            return cum_matrix[end_row][end_col] - cum_matrix[start_row-1][end_col] - cum_matrix[end_row][start_col-1] + cum_matrix[start_row-1][start_col-1];
        }
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */