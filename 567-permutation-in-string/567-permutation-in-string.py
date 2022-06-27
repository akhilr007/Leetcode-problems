class Solution:
    def areEqual(self, l1, l2):
        for i in range(26):
            if(l1[i] != l2[i]):
                return False
        return True
    
    def checkInclusion(self, s1: str, s2: str) -> bool:
        
        if len(s1) > len(s2):
            return False
        
        countS1 = [0]*26
        countS2 = [0]*26
        
        for c in s1:
            countS1[ord(c)-ord("a")] += 1
        
        l = 0
        r = 0
        
        while r < len(s2):
            countS2[ord(s2[r])-ord('a')] += 1
            
            if r - l + 1 == len(s1):
                if self.areEqual(countS1, countS2)==True:
                    return True
            
            if r - l + 1 < len(s1):
                r += 1
            else:
                countS2[ord(s2[l])-ord('a')] -= 1
                l += 1
                r += 1
        
        return False