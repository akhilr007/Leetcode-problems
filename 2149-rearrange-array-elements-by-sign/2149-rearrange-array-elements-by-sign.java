class Solution {
    public int[] rearrangeArray(int[] nums) {
        
        int n = nums.length;
        
        int[] positives = new int[n/2];
        int[] negatives = new int[n/2];
        int i=0, j=0;
        
        for(int num: nums){
            if(num > 0){
                positives[i] = num;
                i++;
            }
            else{
                negatives[j] = num;
                j++;
            }
        }
        
        int[] result = new int[n];
        
        i=0;
        j=0;
        int k=0;
        boolean flag = true;
        
        while(i<n/2 || j<n/2){
            
            if(flag == true){
                result[k++] = positives[i++];
            }
            else{
                result[k++] = negatives[j++]; 
            }
            flag = !flag;
        }
        
        return result;
    }
}