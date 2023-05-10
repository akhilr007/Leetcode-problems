class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int> result;
        
        for(int index=0; index<=n; index++){
            int number = index;
            
            int count=0;
            while(number>0){
                if((number & 1) == 1)
                    count ++;
                number = number >> 1;
            }
            
            result.push_back(count);
        }
        return result;
    }
};