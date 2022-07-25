class Solution:
    """
    approx 
    time complexity -> O(logn + logn)
    space complexity -> O(1)
    """
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        
        start, end = 0, len(nums)-1
        
        firstIndex = -1
        while start <= end:
            mid = (start + end) // 2
            
            if nums[mid] == target:
                firstIndex = mid
                end = mid - 1
            
            elif nums[mid] > target:
                end = mid - 1
            else:
                start = mid + 1
        
        
        start, end = 0, len(nums)-1
        lastIndex = -1
        
        while start <= end:
            mid = (start + end) // 2
            
            if nums[mid] == target:
                lastIndex = mid
                start = mid + 1
            
            elif nums[mid] > target:
                end = mid - 1
            else:
                start = mid + 1
            
        result = [firstIndex, lastIndex]
        return result
    