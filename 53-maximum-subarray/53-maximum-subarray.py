class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        
        res = nums[0]
        cur_sum=0
        
        for num in nums:
            cur_sum += num
            res = max(res, cur_sum)
            
            if cur_sum < 0:
                cur_sum=0
        return res
    
    