class Pair{
    public int element;
    public int idx;
    
    Pair(int element, int idx){
        this.element = element;
        this.idx = idx;
    }
}

class Solution {
    int[] count;
    public Pair[] merge(Pair[] left, Pair[] right){
        
        int n = left.length;
        int m = right.length;
        
        Pair[] res = new Pair[n+m];
        int i=0, j=0, k=0;
        
        while(i<n && j<m){
            
            if(left[i].element <= right[j].element){
                res[k] = right[j];
                j++;
                k++;
            }
            else{
                count[left[i].idx] += m-j;
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
    
    public Pair[] mergesort(Pair[] arr, int l, int h){
        
        if(l == h){
            Pair[] ans = new Pair[1];
            ans[0] = arr[l];
            return ans;
        }
        
        int mid = (l + h)/2;
        
        Pair[] left = mergesort(arr, l, mid);
        Pair[] right = mergesort(arr, mid+1, h);
        
        Pair[] merged = merge(left, right);
        return merged;
    }
    
    public List<Integer> countSmaller(int[] nums) {
        
        int n = nums.length;
        Pair[] arr = new Pair[n];
        
        for(int i=0; i<n; i++){
            arr[i] = new Pair(nums[i], i);
        }
        
        count = new int[n];
        mergesort(arr, 0, n-1);
        List<Integer> ans = new ArrayList<>(count.length);
        for(int i : count){
            ans.add(i);
        }
        return ans;
        
    }
}