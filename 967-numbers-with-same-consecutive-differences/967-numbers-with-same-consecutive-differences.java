class Solution {
    public int[] numsSameConsecDiff(int n, int k) {
        
        List<Integer> res = new ArrayList<>();
        
        for(int i=1; i<=9; i++){
            dfs(n, k, i, 1, i, res);
        }
        
        int[] ans = new int[res.size()];
        for(int i=0; i<res.size(); i++){
            ans[i] = res.get(i);
        }
        
        return ans;
    }
    
        private void dfs(int n, int k, int curr, int counter, int prev, List<Integer> res){
        
        if(counter == n){
            res.add(curr);
            return;
        }
        
        int next = prev + k;
        if(next < 10){
            dfs(n, k, curr*10+next, counter+1, next, res);
        }
        
        next = prev - k;
        if(k != 0 && next >= 0){
            dfs(n, k, curr*10+next, counter+1, next, res);
        }
    }
}