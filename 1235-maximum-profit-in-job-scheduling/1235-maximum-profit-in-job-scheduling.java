class Pair{
    int startTime;
    int endTime;
    int profit;
    
    Pair(int startTime, int endTime, int profit){
        this.startTime = startTime;
        this.endTime = endTime;
        this.profit = profit;
    }
}


class Solution {
    
    public int getNextIndex(Pair[] arr, int l, int curJobEndTime, int r){
        
        int result = r+1;
        while(l<=r){
            int mid = l + (r-l)/2;
            
            if(arr[mid].startTime >= curJobEndTime){
                result = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        
        return result;
    }
    
    public int solve(Pair[] arr, int i, int[] dp){
        
        if(i >= arr.length) return 0;
        if(dp[i] != -1) return dp[i];
        
        int next = getNextIndex(arr, i+1, arr[i].endTime, arr.length-1);
        
        int taken = arr[i].profit + solve(arr, next, dp);
        int notTaken = solve(arr, i+1, dp);
        
        return dp[i] = Math.max(taken, notTaken);
    }
    
    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        
        int n = startTime.length;
        Pair[] arr = new Pair[n];
        
        for(int i=0; i<n; i++){
            arr[i] = new Pair(startTime[i], endTime[i], profit[i]);
        }
        
        Arrays.sort(arr, (a, b) -> a.startTime - b.startTime);
        
        int[] dp = new int[n+1];
        Arrays.fill(dp, -1);
        return solve(arr, 0, dp);
    }
}