func searchInsert(nums []int, target int) int {
    
    n := len(nums)
    
    low, high := 0, n-1
    lower_bound_index := n
    
    for low <= high {
        
        mid := (low + high)>>1
        
        if nums[mid] >= target {
            lower_bound_index = mid
            high = mid - 1
        } else {
            low = mid + 1
        }
    }
    
    return lower_bound_index
}