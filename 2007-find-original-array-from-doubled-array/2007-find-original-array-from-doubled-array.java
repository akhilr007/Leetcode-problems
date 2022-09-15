class Solution {
    public int[] findOriginalArray(int[] changed) {
        
        int n = changed.length;
        if(n % 2 == 1) return new int[] {};
        
        int[] count = new int[100001];
        int[] ans = new int[n/2];
        
        for(int val : changed){
            count[val]++;
        }
        
        int idx=0;
        for(int i=0; i<count.length; i++){
            while(count[i]>0 && i*2<count.length && count[2*i]>0){
                count[i]--;
                count[2*i]--;
                ans[idx++] = i;
            }
        }
        
        for(int i=0; i<count.length; i++){
            if(count[i]>0) return new int[] {};
        }
        
        return ans;
    }
}