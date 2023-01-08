class Solution {
    private int findGCD(int a, int b){
        
        if(b == 0) return a;
        
        return findGCD(b, a % b);
    }
    
    public int maxPoints(int[][] points) {
        
        int n = points.length;
        if(n == 1) return 1;
        
        int result = 0;
        
        for(int i=0; i<n; i++){
            
            Map<String, Integer> map = new HashMap<>();
            
            for(int j=0; j<n; j++){
                
                if(i == j) continue;
                
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                
                int gcd = findGCD(Math.max(dx, dy), Math.min(dx, dy));
                
                String key = dx / gcd + "_" + dy / gcd;
                
                map.put(key, map.getOrDefault(key, 0) + 1);
            }
            
            for(String key : map.keySet()){
                result = Math.max(result, map.get(key) + 1);
            }
        }
        
        return result;
    }
}