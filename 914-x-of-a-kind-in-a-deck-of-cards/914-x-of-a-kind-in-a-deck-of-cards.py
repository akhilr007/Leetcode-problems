class Solution:
    def gcd(self, a, b):
        if b == 0:
            return a
        
        return self.gcd(b, a%b)
    
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        
        m = {}
        
        for x in deck:
            m[x] = m.get(x, 0) + 1
        
        res = m[deck[0]]
        
        for x in m.values():
            if x == 1:
                return False
            
            res = self.gcd(max(res, x), min(res, x))
        
        return True if res > 1 else False