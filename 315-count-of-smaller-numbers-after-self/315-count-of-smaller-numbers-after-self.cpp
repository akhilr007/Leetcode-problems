class Solution {
public:
    vector<pair<int, int>> merge(vector<pair<int, int>>& left, vector<pair<int, int>>& right, vector<int>& count){
        
        int n=left.size(), m=right.size();
        int i=0, j=0;
        int k=0;
        vector<pair<int, int>> res(n+m);
        
        while(i<n and j<m){
            if(left[i].first <= right[j].first){
                res[k] = right[j];
                j++;
                k++;
            }
            else{
                count[left[i].second] += m-j;
                res[k] = left[i];
                i++;
                k++;
            }
        }
        
        while(i<n){
            res[k] = left[i];
            i++;
            k++;
        }
        
        while(j<m){
            res[k] = right[j];
            j++;
            k++;
        }
        
        return res;
    }
    
    vector<pair<int, int>> mergeSort(vector<pair<int, int>>& arr, int lo, int hi, vector<int>& count){
        
        if(lo == hi){
            vector<pair<int, int>> ba(1);
            ba[0]= arr[lo];
            return ba;
        }
        
        int mid = (lo+hi)/2;
        
        vector<pair<int, int>> left = mergeSort(arr, lo, mid, count);
        vector<pair<int, int>> right = mergeSort(arr, mid+1, hi, count);
        
        vector<pair<int, int>> res = merge(left, right, count);
        
        return res;
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        
        int n = nums.size();
        vector<pair<int, int>> arr(n);
        for(int i=0; i<n; i++){
            arr[i] = {nums[i], i};
        }
        
        vector<int> count(n, 0);
        
        mergeSort(arr, 0, n-1, count);
        
        //count[n-1]=0;
        return count;
    }
};