class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        
        if len(s) != len(t):
            return False

        freq = {}

        for c in s:
            freq[c] = freq.get(c, 0) + 1

        for c in t:
            if c not in freq:
                return False
            else:
                freq[c] = freq.get(c)-1
                if freq[c] == 0:
                    del freq[c]
        
        return len(freq) == 0