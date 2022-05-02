class Solution {
public:
    bool isPalindrome(int x) {
        
        long temp= (long)x;
        long res=0;
        
        while(true){
            
            if(temp<=0) break;
            
            int rem = temp%10;
            res = res*10 + rem;
            temp = temp/10;
        }
        
        return res == x;
    }
};