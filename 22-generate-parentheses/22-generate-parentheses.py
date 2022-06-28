class Solution:
    def helperUtil(self, output, opened, closed, res):
        if opened == 0 and closed == 0:
            res.append(output)
            return
        
        if opened != 0:
            self.helperUtil(output + "(", opened-1, closed, res)
        if closed > opened:
            self.helperUtil(output + ")", opened, closed-1, res)
        
        
    def generateParenthesis(self, n: int) -> List[str]:
        
        res = []
        opened, closed = n, n
        self.helperUtil("", opened, closed, res)
        return res