class Solution{
public:
    int count;

    vector<int> merge(vector<int>& left, vector<int>& right){

        int n=left.size(), m=right.size();
        int i=0, j=0;

        while(i<n and j<m){
            if(left[i] > 2LL * right[j]){
                count += (n-i);
                j++;
            }
            else{
                i++;
            }
        }

        i=0, j=0;
        int k=0;
        vector<int> res(n+m);

        // merge them
        while(i<n and j<m){

            if(left[i] < right[j]){
                res[k] = left[i];
                i++;
            }
            else{
                res[k] = right[j];
                j++;
            }
            k++;
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

    vector<int> mergeSort(vector<int>& nums, int lo, int hi){

        if(lo == hi){
            vector<int> ba(1);
            ba[0] = nums[lo];
            return ba;
        }

        int mid = (lo+hi)/2;
        vector<int> left = mergeSort(nums, lo, mid);
        vector<int> right = mergeSort(nums, mid+1, hi);
        vector<int> arr = merge(left, right);
        return arr;
    }

    int reversePairs(vector<int>& nums){
        count=0;
        mergeSort(nums, 0, nums.size()-1);
        return count;
    }
};