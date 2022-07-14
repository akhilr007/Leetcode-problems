class Solution {
    public boolean isPali(String s, int i, int j){
        
        while(i <= j){
            if(s.charAt(i) != s.charAt(j)) return false;
            i++;
            j--;
        }
        
        return true;
    }
    
    public void dfs(int i, String s, List<String> ans, List<List<String>> result){
        
        if(i >= s.length()){
            result.add(new ArrayList(ans));
            return;
        }
        
        for(int j = i; j<s.length(); j++){
            if(isPali(s, i, j)){
                ans.add(s.substring(i, j+1));
                dfs(j+1, s, ans, result);
                ans.remove(ans.size()-1);
            }
        }
    }
    
    public List<List<String>> partition(String s) {
        
        List<List<String>> result = new ArrayList<>();
        List<String> ans = new ArrayList<>();
        
        dfs(0, s, ans, result);
        return result;
    }
}