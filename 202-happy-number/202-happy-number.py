class Solution:
    def isHappy(self, n: int) -> bool:
        
        hashset = set()
        
        while True:
            val = 0
            while n!=0:
                r = n % 10
                val += r * r
                n = n // 10
            
            if val == 1:
                return True
            if val in hashset:
                return False
            
            hashset.add(val)
            n = val
        
        return False