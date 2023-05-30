class Solution {
    public int nCr(int n, int r){
        
        long ans=1;
        
        for(int i=0; i<r; i++){
            
            ans = ans * (n-i);
            ans = ans / (i+1);
        }
        
        return (int)ans;
    }
    
    public List<Integer> generateRow(int row){
        
        List<Integer> rowData = new ArrayList<>();
        rowData.add(1); // nCo
        
        long ans = 1;
        
        for(int col=1; col<row; col++){
            
            ans = ans * (row - col);
            ans = ans / (col);
            
            rowData.add((int)ans);
        }
        return rowData;
    }
    
    public List<List<Integer>> generate(int numRows) {
        
        List<List<Integer>> result = new ArrayList<>();
        
        for(int row=1; row<=numRows; row++){
            result.add(generateRow(row));
        }
        return result;
    }
}