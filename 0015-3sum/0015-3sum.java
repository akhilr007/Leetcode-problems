class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        
        int n = nums.length;
        
        List<List<Integer>> result = new ArrayList<>();
        
        Arrays.sort(nums);
        
        for(int index=0; index<n; index++){
            
            if(index > 0 && nums[index] == nums[index-1])
                continue;
            
            int l=index+1;
            int r=n-1;
            
            while(l<r){
                
                int sum = nums[index] + nums[l] + nums[r];
                
                if(sum < 0){
                    l++;
                }
                else if(sum > 0){
                    r--;
                }
                else{
                    result.add(Arrays.asList(nums[index], nums[l], nums[r]));
                    l++;
                    r--;
                    
                    while(l<r && nums[l] == nums[l-1]) l++;
                    while(l<r && nums[r] == nums[r+1]) r--;
                }
            }
        }
        
        return result;
    }
}