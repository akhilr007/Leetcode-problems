class Solution:
    def numsSameConsecDiff(self, n: int, k: int) -> List[int]:
        
        res = []
        
        def dfs(curr, counter, prev):
            
            if counter == n:
                res.append(curr)
                return
            
            nxt = prev + k
            if nxt < 10:
                dfs(curr*10+nxt, counter+1, nxt)
            
            nxt = prev - k
            if k != 0 and nxt >= 0:
                dfs(curr*10+nxt, counter+1, nxt)
        
        for i in range(1, 10):
            dfs(i, 1, i)
        return res