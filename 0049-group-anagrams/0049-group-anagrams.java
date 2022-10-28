class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        
        grouping = {}
        
        for s in strs:
            tmp = ''.join(sorted(s))
            
            if tmp not in grouping:
                grouping[tmp] = [s]
            else:
                grouping[tmp].append(s)
        
        res = []
        for val in grouping.values():
            res.append(val)
            
        return res
    
            