class Solution {
    public int equalPairs(int[][] grid) {
        
        int n = grid.length;
        int count = 0;
        
        Map<String, Integer> map = new HashMap<>();
        
        for(int[] row: grid){
            String rowString = Arrays.toString(row);
            map.put(rowString, map.getOrDefault(rowString, 0) + 1);
        }
        
        for(int c=0; c<n; c++){
            int[] col = new int[n];
            for(int r=0; r<n; r++){
                col[r] = grid[r][c];
            }
            
            String colString = Arrays.toString(col);
            count += map.getOrDefault(colString, 0);
        }
        return count;
    }
}