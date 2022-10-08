#define pii pair<int, int>
class Solution {
public:
    // -4 -1 1 2
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        int n=nums.size();
        
        int result=nums[0] + nums[1] + nums[2];
        
        for(int i=0; i<n-2; i++){
            
            if(i>0 && nums[i] == nums[i-1]) continue;
            
            int L = i+1;
            int R = n-1;
            
            while(L < R){
                
                int a = nums[i];
                int b = nums[L];
                int c = nums[R];
                int sum = a+b+c;
                
                if(sum == target) return target;
                if(abs(target - sum) < abs(target - result)){
                    result = sum;
                }
                else if(sum > target){
                    R--;
                }
                else{
                    L++;
                    while(L<R && nums[L] == nums[L-1]) L++;
                }
            }
        }
        return result;
        
    }
};