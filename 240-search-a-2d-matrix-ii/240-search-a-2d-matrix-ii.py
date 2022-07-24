class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        
        ROWS, COLS = len(matrix), len(matrix[0])
        
        i, j = 0, COLS-1
        
        while i < ROWS and j >= 0:
            
            if matrix[i][j] == target:
                return True
            
            if matrix[i][j] > target:
                j -= 1
            else:
                i += 1
        return False
    