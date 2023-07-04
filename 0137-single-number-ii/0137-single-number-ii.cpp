class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int n = nums.size();
        
        int result = 0;
        
        for(int bit=0; bit<32; bit++){
            
            // kth bit
            int temp = 1 << bit;
            
            int countZero=0, countOne=0;
            for(auto& num: nums){
                
                if((num & temp) == 0)
                    countZero++;
                else
                    countOne++;
            }
            
            if(countOne % 3 == 1){
                result = (result | temp);
            }
        }
        
        return result;
    }
};