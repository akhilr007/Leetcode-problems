class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        
        output = []
        top, bottom, left, right = 0, len(matrix)-1, 0, len(matrix[0])-1
        
        direction = 1
        
        while top <= bottom and left <= right:
            
            if direction == 1:
                # left to right
                for i in range(left, right+1):
                    output.append(matrix[top][i])
                
                top += 1
                direction = 2
            
            elif direction == 2:
                # top to bottom
                for i in range(top, bottom+1):
                    output.append(matrix[i][right])
                
                right -= 1
                direction = 3
            
            elif direction == 3:
                # right to left
                for i in range(right, left-1, -1):
                    output.append(matrix[bottom][i])
                
                bottom -= 1
                direction = 4
            
            else:
                # bottom to top
                for i in range(bottom, top-1, -1):
                    output.append(matrix[i][left])
                
                left += 1
                direction = 1
                
        return output
    