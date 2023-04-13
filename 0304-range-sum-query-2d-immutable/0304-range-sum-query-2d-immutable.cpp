// question link https://leetcode.com/problems/range-sum-query-2d-immutable/

class NumMatrix {
public:
    vector<vector<int>> cum_matrix;
    NumMatrix(vector<vector<int>> &matrix){
        int n = matrix.size();
        int m = matrix[0].size();

        cum_matrix.resize(n, vector<int>(m, 0));

        cum_matrix[0][0] = matrix[0][0];

        // prefix sum for 1st row
        // row -> constant col -> variable
        for(int col=1; col<m; col++){
            cum_matrix[0][col] = cum_matrix[0][col-1] + matrix[0][col];
        }

        // prefix sum for 1st col
        // col -> constant row -> variable
        for(int row=1; row<n; row++){
            cum_matrix[row][0] = cum_matrix[row-1][0] + matrix[row][0];
        }

        for(int row=1; row<n; row++){
            for(int col=1; col<m; col++){

                cum_matrix[row][col] =  matrix[row][col] + cum_matrix[row-1][col] + 
                                        cum_matrix[row][col-1] - cum_matrix[row-1][col-1];
            }
        }
    }

    int sumRegion(int startRow, int startCol, int endRow, int endCol){

        if(startRow == 0 and startCol == 0){
            return cum_matrix[endRow][endCol];
        }
        else if(startRow == 0){
            return cum_matrix[endRow][endCol] - cum_matrix[endRow][startCol-1];
        }
        else if(startCol == 0){
            return cum_matrix[endRow][endCol] - cum_matrix[startRow-1][endCol];
        }
        else{
            return cum_matrix[endRow][endCol] - cum_matrix[startRow-1][endCol] -
                    cum_matrix[endRow][startCol-1] + cum_matrix[startRow-1][startCol-1];
        }
    }
};