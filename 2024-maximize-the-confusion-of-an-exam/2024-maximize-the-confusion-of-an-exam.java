class Solution {
    int n;
    int result;
    void findMax(char[] str){
        
        int n = str.length;
        int i=0;
        
        while(i<n){
            
            int curLength=0;
            if(str[i] == 'T'){
                curLength=1;
                i++;
                while(i<n && str[i] == 'T'){
                    curLength++;
                    i++;
                }
                result = Math.max(result, curLength);
            }
            else{
                curLength=1;
                i++;
                while(i<n && str[i] == 'F'){
                    curLength++;
                    i++;
                }
                result = Math.max(result, curLength);
            }
        }
    }
    
    void brute(int idx, char[] str, int k){
        
        findMax(str);
        
        if(idx >= n || k <= 0)
            return;
        
        // flip
        str[idx] = str[idx] == 'T' ? 'F' : 'T';
        brute(idx+1, str, k-1);
        
        str[idx] = str[idx] == 'T' ? 'F' : 'T';
        brute(idx+1, str, k);
    }
    
    int better(String answerKey, int k){

        int countF=0;
        
        int i=0;
        int j=0;
        
        // case 1 : "F" -> "T"
        while(j<n){
            
            if(answerKey.charAt(j) == 'F'){
                countF++;
            }
            
            while(countF > k){
                if(answerKey.charAt(i) == 'F')
                    countF--;
                i++;
            }
            
            result = Math.max(result, j-i+1);
            j++;
        }
        
        i=0;
        j=0;
        int countT=0;
        
        // case 2 : "T" -> "F"
        while(j<n){
            
            if(answerKey.charAt(j) == 'T'){
                countT++;
            }
            
            while(countT > k){
                if(answerKey.charAt(i) == 'T')
                    countT--;
                i++;
            }
            
            result = Math.max(result, j-i+1);
            j++;
        }
        
        return result;
    }
    
    public int maxConsecutiveAnswers(String answerKey, int k) {
        
        n = answerKey.length();
        
        return better(answerKey, k);
    }
}