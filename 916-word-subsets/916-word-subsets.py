class Solution:
    def wordSubsets(self, words1: List[str], words2: List[str]) -> List[str]:
        
        def calculateFreqCount(s):
            freq = [0]*26
            for c in s:
                freq[ord(c)-ord("a")] += 1
            return freq
        
        res = []
        maxFreqAcrossB = [0]*26
        
        for word in words2:
            freq = calculateFreqCount(word)
            for i in range(0, 26):
                maxFreqAcrossB[i] = max(maxFreqAcrossB[i], freq[i])
        
        for word in words1:
            freq = calculateFreqCount(word)
            charCountAcrossA = True
            
            for i in range(0, 26):
                if freq[i] < maxFreqAcrossB[i]:
                    charCountAcrossA = False
                    break
            
            if charCountAcrossA:
                res.append(word)
        
        return res
    
        