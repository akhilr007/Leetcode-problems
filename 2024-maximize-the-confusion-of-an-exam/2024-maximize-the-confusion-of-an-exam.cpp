class Solution {
public:
    void findMax(string& answerKey, int& result){
        
        int n = answerKey.length();
        
        int length=0;
        int i=0;
        
        while(i<n){
            
            if(answerKey[i] == 'T'){
                length = 1;
                i++;
                
                while(i<n && answerKey[i] == 'T'){
                    length++;
                    i++;
                }
                result = max(result, length);
            }
            else{
                length = 1;
                i++;
                
                while(i<n && answerKey[i] == 'F'){
                    length++;
                    i++;
                }
                result = max(result, length);
            }
        }
    }
    
    void solve(int idx, string& answerKey, int k, int& result){
        
        findMax(answerKey, result);
        
        if(idx >= answerKey.length() || k<=0)
            return;
        
        // flip
        answerKey[idx] = answerKey[idx] == 'T' ? 'F' : 'T';
        
        solve(idx+1, answerKey, k-1, result);
        
        // unflip
        answerKey[idx] = answerKey[idx] == 'T' ? 'F' : 'T';
        
        solve(idx+1, answerKey, k, result);
        
    }
    
    int better(string answerKey, int k){
        
        int n = answerKey.length();
        int result = 0;
        // case1 -> f -> t
        
        int countF=0;
        int i=0;
        int j=0;
        
        while(j<n){
            
            if(answerKey[j] == 'F'){
                countF++;
            }
            
            while(countF > k){
               if(answerKey[i] == 'F'){
                    countF--;
                } 
                i++;
            }
            
            result = max(result, j-i+1);
            j++;
        }
        
        int countT=0;
        i=0;
        j=0;
        
        while(j<n){
            
            if(answerKey[j] == 'T'){
                countT++;
            }
            
            while(countT > k){
               if(answerKey[i] == 'T'){
                    countT--;
                } 
                i++;
            }
            
            result = max(result, j-i+1);
            j++;
        }
        
        return result;
    }
    
    int optimal(string answerKey, int k){
        
        int n = answerKey.length();
        
        int countT = 0;
        int countF = 0;
        
        int i=0;
        int j=0;
        
        int result = 0;
        
        while(j<n){
            
            answerKey[j] == 'T' ? countT++ : countF++;
            
            while(min(countT, countF) > k){
                answerKey[i] == 'T' ? countT-- : countF--;
                i++;
            }
            
            result = max(result, j-i+1);
            j++;
        }
        return result;
    }
    
    int maxConsecutiveAnswers(string answerKey, int k) {
        
        return optimal(answerKey, k);
    }
};