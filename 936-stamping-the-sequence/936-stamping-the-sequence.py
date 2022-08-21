class Solution:
    
    def update(self, curr, i, stamp):
        for j in range(len(stamp)):
            curr[j+i] = "*"
    
    def findIndex(self, curr, stamp):
        
        for i in range(0, len(curr) - len(stamp) + 1):
            j, s = 0, i
            isNotStarChar = False
            while s<len(curr) and j<len(stamp) and (curr[s] == "*" or curr[s] == stamp[j]):
                if curr[s] != "*":
                    isNotStarChar = True
                s += 1
                j += 1
            
            if j == len(stamp) and isNotStarChar:
                return i
        
        return -1
    
        
    def movesToStamp(self, stamp: str, target: str) -> List[int]:
        
        curr, targetStr = list(target), list("*"*len(target))
        res = []
        
        while curr != targetStr:
            
            stampIdx = self.findIndex(curr, stamp)
            
            if stampIdx < 0:
                return []
            else:
                self.update(curr, stampIdx, stamp)
            
            res.append(stampIdx)
        
        res.reverse()
        return res
    
            