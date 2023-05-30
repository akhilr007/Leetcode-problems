class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        
        int n = nums.length;
        
        HashSet<List<Integer>> ans = new HashSet<>();
        HashSet<Long> hashset;
        
        for(int i=0; i<n; i++){
    
            for(int j=i+1; j<n; j++){
                
                hashset = new HashSet<>();
                
                for(int k=j+1; k<n; k++){
                    
                    long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    long fourth = target - sum;
                    
                    if(hashset.contains(fourth) == true){
                        
                        List<Integer> list = Arrays.asList(nums[i], nums[j], nums[k], (int)fourth);
                        Collections.sort(list);
                        
                        ans.add(list);
                    }
                    
                    hashset.add((long)nums[k]);
                }
            }
        }
        
        List<List<Integer>> result = new ArrayList<>(ans);
        return result;
        
        
    }
}