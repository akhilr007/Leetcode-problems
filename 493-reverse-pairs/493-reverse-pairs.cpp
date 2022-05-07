class Solution {
public:
    int merge(vector<int>& nums, int lo, int mid, int hi){
        
        int count=0;
        int j=mid+1;
        
        for(int i=lo; i<=mid; i++){
            while(j<=hi and nums[i] > 2LL * nums[j]){
                j++;
            }
            
            count += (j-(mid+1));
        }
        
        vector<int> temp;
        int left=lo, right=mid+1;
        
        while(left<=mid and right<=hi){
            
            if(nums[left] <= nums[right]){
                temp.push_back(nums[left++]);
            }
            else{
                temp.push_back(nums[right++]);
            }
        }
        
        while(left <= mid){
            temp.push_back(nums[left++]);
        }
        
        while(right <= hi){
            temp.push_back(nums[right++]);
        }
        
        for(int i=lo; i<=hi; i++){
            nums[i] = temp[i-lo];
        }
        
        return count;
        
    }
    
    int mergeSort(vector<int>& nums, int lo, int hi){
        
        if(lo >= hi){
            return 0;
        }
        
        int mid = (lo+hi)/2;
        
        int inv = mergeSort(nums, lo, mid);
        inv += mergeSort(nums, mid+1, hi);
        inv += merge(nums, lo, mid, hi);
        return inv;
    }
    
    int reversePairs(vector<int>& nums) {
        
        return mergeSort(nums, 0, nums.size()-1);
    }
};