class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        
        ROWS, COLS = len(matrix), len(matrix[0])
        
        rows = [1]*ROWS
        cols = [1]*COLS
        
        for i in range(ROWS):
            for j in range(COLS):
                if matrix[i][j] == 0:
                    rows[i] = 0
                    cols[j] = 0
                    
        
        for i in range(ROWS):
            for j in range(COLS):
                if rows[i] == 0 or cols[j] == 0:
                    matrix[i][j] = 0
        
        
        