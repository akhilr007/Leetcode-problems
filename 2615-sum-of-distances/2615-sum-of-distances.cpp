class Solution {
public:
    /*
        1 -> [0, 2, 3, 5]
        
        
        2 -> (2-0) (3-2)(5-2)
    */
    vector<long long> distance(vector<int>& nums) {
        
        int n = nums.size();
        
        map<int, vector<int>> mpp;
        for(int i=0; i<n; i++){
            mpp[nums[i]].push_back(i);
        }
        
        vector<long long> arr(n, 0);
        
        for(auto it: mpp){
            
            vector<int> indexes = it.second;
            int size = indexes.size();
            
            long long total_sum = 0;
            for(auto el: indexes)
                total_sum += el;
            
            cout << it.first << " total sum: " << total_sum << endl;
            
            long long prev_sum = 0;
            
            for(int i=0; i<indexes.size(); i++){
                
                int index = indexes[i];
                
                long long post_sum = total_sum - prev_sum - index;
                
                arr[index] += (index * (long long)i);
                
                arr[index] -= prev_sum;
                
                arr[index] -= (index * (long long)(size-i-1));
                
                arr[index] += post_sum;
                
                prev_sum += index;
                
            }
        }
        
        return arr;
    }
};