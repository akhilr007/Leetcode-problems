class Solution:
    def longestPalindrome(self, words: List[str]) -> int:
        
        fmap = {}
        for word in words:
            fmap[word] = fmap.get(word, 0)+1
        
        centerUsed = False
        result = 0
        
        for word in words:
            rev = word[::-1]
            
            if rev != word:
                if fmap[word]>0 and fmap.get(rev, 0)>0:
                    result += 4;
                    fmap[word] -= 1
                    fmap[rev] -= 1
            else:
                if fmap[word] >= 2:
                    result += 4
                    fmap[word] -= 2
                elif fmap[word] == 1 and centerUsed == False:
                    result += 2
                    fmap[word] -= 1
                    centerUsed = True
        return result
    
            
            