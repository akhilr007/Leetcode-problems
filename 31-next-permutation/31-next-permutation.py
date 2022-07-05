class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        
        first = len(nums)-1
        
        while first >= 1 and nums[first-1] >= nums[first]:
            first -= 1
        
        if first == 0:
            nums.sort()
            return
        
        first -= 1
        
        second = len(nums)-1
        
        while first < second and nums[first] >= nums[second]:
            second -= 1
            
        nums[first], nums[second] = nums[second], nums[first]
        
        start = first+1
        end = len(nums)-1
        
        while start < end:
            nums[start], nums[end] = nums[end], nums[start]
           
            start += 1
            end -= 1
        
        