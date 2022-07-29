class Solution:
    def isMatching(self, word, pattern):
        
        patternMapping = {}
        wordSet = set()
        
        for i in range(len(pattern)):
            wch = word[i]
            pch = pattern[i]
            
            if pch in patternMapping:
                if patternMapping[pch] != wch:
                    return False
            else:
                if wch in wordSet:
                    return False
                patternMapping[pch] = wch
                wordSet.add(wch)
        return True
    
    def findAndReplacePattern(self, words: List[str], pattern: str) -> List[str]:
        
        res = []
        for word in words:
            if self.isMatching(word, pattern):
                res.append(word)
        
        return res
        