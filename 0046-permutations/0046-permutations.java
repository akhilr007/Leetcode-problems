class Solution {
    private void solve(int idx, int[] nums, List<List<Integer>> permutations){
        
        if(idx >= nums.length){
            List<Integer> temp = new ArrayList<>();
            for(int x: nums) temp.add(x);
            
            permutations.add(temp);
            return;
        }
        
        for(int i=idx; i<nums.length; i++){
            swap(idx, i, nums);
            solve(idx+1, nums, permutations);
            swap(idx, i, nums);
        }
    }
    
    private void swap(int a, int b, int[] nums){
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }
    
    public List<List<Integer>> permute(int[] nums) {

        int n=nums.length;
        List<List<Integer>> permutations = new ArrayList<>();
        solve(0, nums, permutations);
        return permutations;
    }
}