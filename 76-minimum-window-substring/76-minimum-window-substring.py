class Solution:
    def minWindow(self, s: str, t: str) -> str:
        
        freq = [0]*256
        
        count = 0
        for c in t:
            if freq[ord(c) - ord("a")] == 0:
                count += 1
            freq[ord(c) - ord("a")] += 1
            
        
        l, r = 0, 0
        start, end = 0, 0
        res = 1000000
        
        while r < len(s):
            
            freq[ord(s[r]) - ord("a")] -= 1
            
            if freq[ord(s[r]) - ord("a")] == 0:
                count -= 1
                
            if count == 0:
                
                while count == 0:
                    if res > r-l+1:
                        res = r-l+1
                        start = l
                        end = start + r-l+1
                        
                    freq[ord(s[l]) - ord("a")] += 1
                    if freq[ord(s[l]) - ord("a")] == 1:
                        count += 1
                    l += 1
                    
            r += 1
        
        
        if res == 1000000:
            return ""
        
        return s[start : end]
        