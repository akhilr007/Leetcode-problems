func search(nums []int, target int) int {
    
    low := 0
    high := len(nums)-1
    
    return binarySearch(nums, low, high, target)
}

func binarySearch(nums []int, low int, high int, target int) int {
    
    if low > high {
        return -1
    }
    
    mid := (low + high) >> 1
    
    if target == nums[mid]{
        return mid
    } else if target > nums[mid] {
        return binarySearch(nums, mid + 1, high, target)
    } else{
        return binarySearch(nums, low, mid - 1, target)
    }
}