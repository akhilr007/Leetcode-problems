class Solution {
    Map<Pair<Integer, Integer>, Integer> map = new HashMap<>();
    
    public int upperBound(int[] arr, int target){
        
        int low = 0;
        int high = arr.length-1;
        
        int upper_bound = arr.length;
        
        while(low <= high){
            
            int mid = (low + high) >> 1;
            
            if(arr[mid] > target){
                upper_bound = mid;
                high = mid -1 ;
            }
            else{
                low = mid + 1;
            }
        }
        
        return upper_bound;
    }
    
    public int dfs(int idx, int[] arr1, int[] arr2, int prev){
        
        if(idx >= arr1.length)
            return 0;
        
        if(map.containsKey(new Pair<>(idx, prev))) {
            return map.get(new Pair<>(idx, prev));
        }
        
        int result1 = (int)1e9;
        if(arr1[idx] > prev){
            result1 = dfs(idx+1, arr1, arr2, arr1[idx]);
        }
        
        int result2 = (int)1e9;
        int j = upperBound(arr2, prev);
        
        if(j != arr2.length){
            result2 = 1 + dfs(idx+1, arr1, arr2, arr2[j]);
        }
        
        int cost = Math.min(result1, result2);
        map.put(new Pair<>(idx, prev), cost);
        return cost;
    }
    
    public int makeArrayIncreasing(int[] arr1, int[] arr2) {
        
        Arrays.sort(arr2);
        
        int result = dfs(0, arr1, arr2, Integer.MIN_VALUE);
        
        return result == 1e9 ? -1 : result;
    }
}