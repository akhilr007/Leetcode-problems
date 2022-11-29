class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        
        permutations=[]
        size = len(nums)
        
        def permute(idx):
            if idx>=size:
                permutations.append(nums.copy())
                return
            
            for i in range(idx, size):
                nums[idx], nums[i] = nums[i], nums[idx]
                permute(idx+1)
                nums[idx], nums[i] = nums[i], nums[idx]
        permute(0)
        return permutations
    