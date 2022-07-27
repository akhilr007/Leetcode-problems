class Solution {
    public int[][] merge(int[][] intervals) {
        
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));
        List<int[]> res = new ArrayList<>();
        res.add(intervals[0]);
        
        for(int i=0; i<intervals.length; i++){
            
            int start = intervals[i][0];
            int end = intervals[i][1];
            
            if(res.get(res.size()-1)[1] >= start){
                res.get(res.size()-1)[1] = Math.max(res.get(res.size()-1)[1], end);
            }
            else{
                res.add(intervals[i]);
            }
        }
        
        return res.toArray(new int[res.size()][]);
    }
}