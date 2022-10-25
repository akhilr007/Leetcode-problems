class Solution:
    def arrayStringsAreEqual(self, word1: List[str], word2: List[str]) -> bool:
        
        i, j = 0, 0
        m, n = 0, 0
        
        while i<len(word1) and j<len(word2):
            
            ch1, ch2 = word1[i][m], word2[j][n]
            m += 1
            n += 1
            if ch1 != ch2:
                return False
            
            if m >= len(word1[i]):
                i += 1
                m = 0
            
            if n >= len(word2[j]):
                j += 1
                n = 0
        
        return i == len(word1) and j == len(word2)
    