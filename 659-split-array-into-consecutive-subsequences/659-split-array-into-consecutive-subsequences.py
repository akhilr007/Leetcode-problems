class Solution:
    def isPossible(self, nums: List[int]) -> bool:
        
        fm = {}
        hm = {}
        
        for num in nums:
            fm[num] = fm.get(num, 0) + 1
        
        for x in nums:
            if fm[x] == 0:
                continue
            elif (x in hm) and (hm[x] > 0):
                hm[x] -= 1
                hm[x+1] = hm.get(x+1, 0) + 1
                fm[x] -= 1
            elif (x in fm and fm[x]>0) and (x+1 in fm and fm[x+1]>0) and (x+2 in fm and fm[x+2]>0):
                fm[x] -= 1
                fm[x+1] -= 1
                fm[x+2] -= 1
                hm[x+3] = hm.get(x+3, 0) + 1
            else:
                return False
        return True
    