class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        
        pascal = []
        
        for i in range(0, numRows):
            ans = []
            for j in range(0, i+1):
                if j == 0 or j == i:
                    ans.append(1)
                else:
                    val = pascal[i-1][j-1] + pascal[i-1][j]
                    ans.append(val)
            
            pascal.append(ans)
            
        return pascal
    