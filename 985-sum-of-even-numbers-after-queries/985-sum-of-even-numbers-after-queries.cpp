class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        vector<int> ans;
        int evenSum=0;
        for(auto val : nums){
            if(val % 2 == 0) evenSum += val;
        }
        
        for(int i=0; i<queries.size(); i++){
            int val = queries[i][0];
            int index = queries[i][1];
            
            // odd ke saath odd add karne pe hi even sum milega
            if(nums[index] % 2){
                if(val % 2 ){
                    evenSum += nums[index] + val;
                }
                nums[index] += val;
            }
            else{
                if(val % 2 == 0){
                    evenSum += val;
                }
                else{
                    evenSum -= nums[index];
                }
                
                nums[index] += val;
                
            }
            
            ans.push_back(evenSum);
        }
        return ans;
    }
};