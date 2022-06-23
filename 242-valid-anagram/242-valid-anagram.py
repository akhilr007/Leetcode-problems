class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        
        if len(s) != len(t):
            return False
    
        hashmap = {}
        
        for i in range(len(s)):
            hashmap[s[i]] = hashmap.get(s[i], 0) + 1
            
        
        for i in range(len(t)):
            if t[i] in hashmap:
                hashmap[t[i]] = hashmap.get(t[i])-1
                if hashmap[t[i]] == 0:
                    del hashmap[t[i]]
        
        return len(hashmap) == 0