func findFirstOccurence(nums []int, target int, n int) int{
    
    first_occurence := -1
    low, high := 0, n-1
    
    for low <= high {
        
        mid := (low + high) >> 1
        
        if nums[mid] == target {
            first_occurence = mid
            high = mid - 1
        } else if nums[mid] > target {
            high = mid - 1
        } else {
            low = mid + 1
        }
    }
    
    return first_occurence
}

func findLastOccurence(nums []int, target int, n int) int{
    
    last_occurence := -1
    low, high := 0, n-1
    
    for low <= high {
        
        mid := (low + high) >> 1
        
        if nums[mid] == target {
            last_occurence = mid
            low = mid + 1
        } else if nums[mid] > target {
            high = mid - 1
        } else {
            low = mid + 1
        }
    }
    
    return last_occurence
}

func searchRange(nums []int, target int) []int {
    
    n := len(nums)
    
    firstOccurence := findFirstOccurence(nums, target, n)
    if firstOccurence == -1 {
        return []int {-1, -1}
    }
    
    lastOccurence := findLastOccurence(nums, target, n)
    
    return []int{firstOccurence, lastOccurence}
}