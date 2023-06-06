class Solution {
    public int removeDuplicates(int[] nums) {
        
        List<Integer> uniqueElements = new ArrayList<>();
        for(int num: nums){
            if(uniqueElements.size() == 0 || uniqueElements.get(uniqueElements.size()-1) != num){
                uniqueElements.add(num);
            }
        }
        
        for(int i=0; i<uniqueElements.size(); i++){
            nums[i] = uniqueElements.get(i);
        }
        
        return uniqueElements.size();
    }
}