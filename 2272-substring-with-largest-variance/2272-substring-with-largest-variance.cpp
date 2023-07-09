class Solution {
public:
    int largestVariance(string s) {
        
        vector<int> count(26, 0);
        for(auto& ch: s)
            count[ch-'a']=1;
        
        int n = s.length();
        int result=0;
        
        for(char first='a'; first<='z'; first++){
            
            if(count[first-'a'] != 1)
                continue;
            
            for(char second='a'; second<='z'; second++) {
                
                if(count[second-'a'] != 1)
                    continue;
                
                int firstCount=0;
                int secondCount=0;
                bool isSecondPresent=false;
                
                for(char& ch: s){
                    
                    if(ch == first)
                        firstCount++;
                    if(ch == second)
                        secondCount++;
                    
                    if(secondCount > 0){
                        result = max(result, firstCount-secondCount);
                    }
                    else{
                        if(isSecondPresent==true){
                            result = max(result, firstCount-1);
                        }
                    }
                    
                    if(secondCount > firstCount){
                        firstCount = 0;
                        secondCount = 0;
                        isSecondPresent = true;
                    }
                }
            }
        }
        
        return result;
    }
};