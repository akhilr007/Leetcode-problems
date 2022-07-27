class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        
        sums = sum(nums)
        
        lsum, rsum = 0, sums
        
        for i in range(len(nums)):
            rsum = rsum - nums[i]
            
            if rsum == lsum:
                return i
            lsum += nums[i]
        
        return -1
    