class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        
        hashmap = defaultdict()
        
        for s in strs:
            temp = ''.join(sorted(s))
            if temp in hashmap:
                hashmap[temp].append(s)
            else:
                hashmap[temp] = [s]
            
        return hashmap.values()