class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        
        hashset = set()
        
        for i in range(9):
            for j in range(9):
                
                if board[i][j] == ".":
                    continue
                    
                ith = str(i)
                jth = str(j)
                
                no = ""
                no += board[i][j]
                
                if (no+"r"+ith in hashset or 
                    no+"c"+jth in hashset or 
                    no+"b"+ str(i//3) + str(j//3) in hashset):
                    return False
                
                hashset.add(no+"r"+ith)
                hashset.add(no+"c"+jth)                
                hashset.add(no+"b"+str(i//3)+str(j//3))    
        
        return True