class Solution {
    public int upperBound(char[] letters, char target){
        
        int upper_bound = letters.length;
        int low = 0;
        int high = letters.length-1;
        
        while(low <= high){
            
            int mid = (low + high) >> 1;
            
            if(letters[mid] > target){
                upper_bound = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        
        return upper_bound;
    }
    
    public char nextGreatestLetter(char[] letters, char target) {
        
        int n = letters.length;
        
        int index = upperBound(letters, target);
        
        if(index == n)
            return letters[0];
        
        return letters[index];
    }
}