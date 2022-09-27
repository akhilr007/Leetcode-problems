class Solution {
    public String pushDominoes(String dominoes) {
        
        int n = dominoes.length();
        
        int nearestLeft = -1;
        int[] left = new int[n];
        
        for(int i=n-1; i>=0; i--){
            
            char ch = dominoes.charAt(i);
            if(ch == 'L'){
                nearestLeft = i;
            }
            else if(ch == 'R'){
                nearestLeft = -1;
            }
            
            left[i] = nearestLeft;
        }
        
        int nearestRight = -1;
        int[] right = new int[n];
        
        for(int i=0; i<n; i++){
            
            char ch = dominoes.charAt(i);
            if(ch == 'R'){
                nearestRight = i;
            }
            else if(ch == 'L'){
                nearestRight = -1;
            }
            
            right[i] = nearestRight;
        }
        
        
        StringBuffer ans= new StringBuffer();
        for(int i=0; i<n; i++){
            
            char ch = dominoes.charAt(i);
            
            if(ch == '.'){
                
                int nearLeft = left[i];
                int nearRight = right[i];
                
                int leftDiff = nearLeft == -1 ? Integer.MAX_VALUE : Math.abs(nearLeft - i);
                int rightDiff = nearRight == -1 ? Integer.MAX_VALUE : Math.abs(nearRight - i);
                
                if(leftDiff == rightDiff){
                    ans.append('.');
                }
                else if(leftDiff < rightDiff){
                    ans.append('L');
                }
                else{
                    ans.append('R');
                }
            }
            else{
                ans.append(ch);
            }
        }
        
        return ans.toString();
    }
}