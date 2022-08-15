class Solution:
    def romanToInt(self, s: str) -> int:
        
        charToInt = {
            "I" : 1,
            "V" : 5,
            "X" : 10,
            "L" : 50,
            "C" : 100,
            "D" : 500,
            "M" : 1000
        }
        
        result = charToInt[s[0]]
        
        for i in range(1, len(s)):
            
            if charToInt[s[i]] > charToInt[s[i-1]]:
                result += charToInt[s[i]] - (2*charToInt[s[i-1]])
            else:
                result += charToInt[s[i]]
                
        return result
    