class Solution {
    public boolean canMakeArithmeticProgression(int[] arr) {
        
        int n = arr.length;
        Arrays.sort(arr);
        
        int difference = arr[1] - arr[0];
        
        for(int i=2; i<n; i++){
            
            int curDifference = arr[i] - arr[i-1];
            if(curDifference != difference)
                return false;
        }
        
        return true;
    }
}