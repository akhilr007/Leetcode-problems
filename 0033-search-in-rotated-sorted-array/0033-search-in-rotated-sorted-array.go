func search(nums []int, target int) int {
    
    n := len(nums)
    
    low, high := 0, n-1
    
    for low <= high {
        
        mid := (low + high) >> 1
        
        if nums[mid] == target {
            return mid
        }
        
        // is left part sorted
        if nums[low] <= nums[mid] {
            
            // if target lies b/w low and mid, eliminate right part
            if target >= nums[low] && target <= nums[mid]{
                high = mid - 1
            }else{
                low = mid + 1
            }
        }else{
            if target >= nums[mid] && target <= nums[high] {
                low = mid + 1
            } else {
                high = mid - 1
            }
        }
    }
    
    return -1
}