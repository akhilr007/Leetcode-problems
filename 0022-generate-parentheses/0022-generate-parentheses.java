class Solution {
    private void backtrack(int open, int close, List<String> ans, String p){
        
        if(open == 0 && close == 0){
            ans.add(p);
            return;
        }
        
        if(open != 0) backtrack(open-1, close, ans, p + "(");
        if(close>open) backtrack(open, close-1, ans, p + ")");
    }
    
    public List<String> generateParenthesis(int n) {
        
        List<String> ans = new ArrayList<>();
        if(n == 0) return ans;
        
        int open=n, close=n;
        backtrack(open, close, ans, "");
        return ans;
    }
}