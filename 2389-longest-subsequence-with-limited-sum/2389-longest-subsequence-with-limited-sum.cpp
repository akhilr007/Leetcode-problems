class Solution {
private:
    vector<int> bruteForce(vector<int>& nums, vector<int>& queries){
        
        int n = nums.size();
        int m = queries.size();
        vector<int> ans(m);
        
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<m; i++){
            int sum=0;
            int j;
            for(j=0; j<n; j++){
                sum += nums[j];
                if(sum > queries[i]){
                    ans[i] = j;
                    break;
                }
            }
            
            if(sum <= queries[i]){
                ans[i] = j;
            }
        }
        
        return ans;
    }
public:
    
    int bsearch(int low, int high, vector<int>& csum, int num){
        
        int result=csum.size();
        while(low <= high){
            int mid = low + (high - low)/2;
            
            if(csum[mid] > num){
                result = mid; 
                high = mid - 1;
            }
            else low = mid + 1;
        }
        
        return result;
    }
    
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        
        int n = nums.size();
        int m = queries.size();
        sort(begin(nums), end(nums));
        
        vector<int> csum(n);
        csum[0] = nums[0];
        for(int i=1; i<n; i++){
            csum[i] = csum[i-1] + nums[i];
        }
        
        vector<int> ans(m);
        for(int i=0; i<m; i++){
            
            int num = queries[i];
            int indexGreaterThanJustNum = bsearch(0, n-1, csum, num);
            ans[i] = indexGreaterThanJustNum;
        }
        return ans;
    }
};