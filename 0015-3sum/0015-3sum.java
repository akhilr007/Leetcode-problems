class Solution { 
    public List<List<Integer>> threeSum(int[] nums) {
        
        int n = nums.length;
        HashSet<List<Integer>> ans = new HashSet<>();
        HashSet<Integer> hashset = new HashSet<>();
        
        for(int i=0; i<n; i++){
            hashset = new HashSet<>();
            for(int j=i+1; j<n; j++){
                
                int third = -(nums[i] + nums[j]);
                
                if(hashset.contains(third) == true){
                    
                    List<Integer> list = new ArrayList<>();
                    list.addAll(Arrays.asList(nums[i], nums[j], third));
                    Collections.sort(list);
                    ans.add(list);
                }
                
                hashset.add(nums[j]);
            }
        }
        
        List<List<Integer>> result = new ArrayList<>(ans);
        return result;
    }
}