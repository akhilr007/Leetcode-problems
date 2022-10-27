class Solution {
    public int largestOverlap(int[][] A, int[][] B) {
        
        List<int[]> p1 = new ArrayList<>();
        List<int[]> p2 = new ArrayList<>();
        
        int len = A.length;
        
        for(int i=0; i<len; i++){
            
            for(int j=0; j<len; j++){
                
                if(A[i][j] == 1){
                    p1.add(new int[] {i, j});   
                }

                if(B[i][j] == 1){
                    p2.add(new int[]{i,j});
                }
            }
        }
        
        Map<String, Integer> map = new HashMap<>();
        int ans = 0;
        for(int[] a: p1){
            for(int[] b: p2){
                
                int x = a[0] - b[0];
                int y = a[1] - b[1];
                
                String s = x + "#" + y;
                map.put(s, map.getOrDefault(s, 0)+1);
                ans = Math.max(ans, map.get(s));
            }
        }
        
        return ans;
    }
}