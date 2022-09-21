class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        vector<int> ans;
        unordered_map<int, int> odds, evens;
        
        int evenSum=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]%2){
                odds[i] = nums[i];
            }
            else{
                evens[i] = nums[i];
                evenSum += nums[i];
            }
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
                    nums[index] += val;
                }
                else{
                    evenSum -= nums[index];
                    nums[index] += val;
                }
                
            }
            
            cout<<nums[index]<<" ";
            
            ans.push_back(evenSum);
        }
        return ans;
    }
};