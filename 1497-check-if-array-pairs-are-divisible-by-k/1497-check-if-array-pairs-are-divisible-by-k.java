class Solution {
    public boolean canArrange(int[] arr, int k) {
        
        if(arr.length % 2 == 1) return false;
        
        Map<Integer, Integer> fmap = new HashMap<>();
        for(int a : arr){
            int rem = ((a%k)+k)%k;
            fmap.put(rem, fmap.getOrDefault(rem, 0) + 1);
        }
        
        for(int a : arr){
            
            int rem = ((a%k)+k)%k;
            
            if(rem == 0){
                if(fmap.get(rem) % 2 == 1) return false;
            }
            else{
                int xFreq = fmap.get(rem);
                int k_xFreq = fmap.getOrDefault(k-rem, 0);
                
                if(xFreq != k_xFreq) return false;
            }
        }
        
        return true;
    }
}