func search(nums []int, target int) bool {
    
    n := len(nums)
    
    low, high := 0, n-1
    
    for low <= high {
        
        mid := (low + high) >> 1
        
        if nums[mid] == target {
            return true
        }
        
        if nums[low] == nums[mid] && nums[mid] == nums[high] {
            low++
            high--
            continue
        }
        
        if nums[low] <= nums[mid]{
            if target >= nums[low] && target <= nums[mid] {
                high = mid - 1
            } else {
                low = mid + 1
            }
        } else {
            if target >= nums[mid] && target <= nums[high] {
                low = mid + 1
            } else {
                high = mid - 1
            }
        }
    }
    
    return false
}