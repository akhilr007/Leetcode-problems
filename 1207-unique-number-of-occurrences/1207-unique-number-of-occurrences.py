class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        
        count = [0]*2001
        for num in arr:
            count[num + 1000] += 1
        
        count.sort()
        for i in range(1, len(count)-1):
            if count[i]>0 and count[i] == count[i+1]:
                return False
        return True
    