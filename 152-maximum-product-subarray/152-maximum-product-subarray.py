class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        
        res, cur_product = nums[0], 1
        
        for num in nums:
            cur_product *= num
            res = max(res, cur_product)
            if cur_product == 0:
                cur_product = 1
        
        cur_product = 1
        for i in range(len(nums)-1, -1, -1):
            cur_product *= nums[i]
            res = max(res, cur_product)
            if cur_product == 0:
                cur_product = 1
        return res
    
    