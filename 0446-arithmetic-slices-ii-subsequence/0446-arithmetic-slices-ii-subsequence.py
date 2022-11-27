class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        
        maps = [{} for x in range(len(nums))]
        result=0
        N = len(nums)
        
        for i in range(1, N):
            for j in range(0, i):
                cd = nums[i]-nums[j]
                
                countAtJ = maps[j].get(cd, 0)
                countAtI = maps[i].get(cd, 0)
                
                result += countAtJ
                maps[i][cd] = countAtI + countAtJ + 1
        
        return result
    