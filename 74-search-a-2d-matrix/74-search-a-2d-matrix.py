class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        
        n = len(matrix)
        m = len(matrix[0])
        
        start, end = 0, n*m - 1
        
        while start <= end:
            
            mid = (start + end)//2
            
            row, col = mid//m, mid % m
            
            if matrix[row][col] == target:
                return True
            
            if matrix[row][col] > target:
                end = mid - 1
            else:
                start = mid + 1
        return False