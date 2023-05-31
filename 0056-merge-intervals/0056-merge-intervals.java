class Solution {
    public int[][] brute(int[][] intervals){
        
        int n = intervals.length;
        List<int[]> result = new ArrayList<>();
        Arrays.sort(intervals, (a, b) -> a[0] - b[0]);
        
        for(int i=0; i<n; i++){
            
            int start = intervals[i][0];
            int end = intervals[i][1];
            
            if(result.size()>0 && result.get(result.size()-1)[1] >= end){
                continue;
            }
            
            for(int j=i+1; j<n; j++){
                
                if(intervals[j][0] <= end){
                    end = Math.max(end, intervals[j][1]);
                }
                else{
                    break;
                }
            }
            
            result.add(new int[] {start, end});
        }
        return result.toArray(new int[result.size()][]);
    }
    public int[][] merge(int[][] intervals) {
        
        int n = intervals.length;
        Arrays.sort(intervals, (a, b) -> a[0]-b[0]);
        
        List<int[]> result = new ArrayList<>();
        
        for(int i=0; i<n; i++){
            
            if(result.size()==0 || intervals[i][0] > result.get(result.size()-1)[1]){
                result.add(intervals[i]);
            }
            else{
                result.get(result.size()-1)[1] = Math.max(result.get(result.size()-1)[1], intervals[i][1]);
            }
        }
        
        return result.toArray(new int[result.size()][]);
    }
}