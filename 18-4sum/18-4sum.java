class Solution {
    public List<List<Integer>> fourSum(int[] arr, int k) {
        
        int n = arr.length;
        
        List<List<Integer>> ans = new ArrayList<>();
        if(n==0 || n==1 || n==2 || n==3) return ans;
    
        Arrays.sort(arr);
        for(int i=0; i<arr.length; i++){
            
            while(i>0 && i<n && arr[i] == arr[i-1]) i++;
            
            for(int j=i+1; j<arr.length; j++){
                
               while(j>i+1 && j<n && arr[j] == arr[j-1]) j++;
                
                int c=j+1;
                int d=arr.length-1;
                
                while(c < d){
                    
                    long sum = (long)arr[i] + (long)arr[j] + (long)arr[c] + (long)arr[d];
                    //System.out.println(sum);
                    if(sum == k){
                        ArrayList<Integer> res = new ArrayList<>();
                        res.add(arr[i]);
                        res.add(arr[j]);
                        res.add(arr[c]);
                        res.add(arr[d]);
                        ans.add(res);
                        c++;
                        
                        while(arr[c] == arr[c-1] && c < d) c++;
                        
                    }
                    
                    else if(sum > k){
                        d--;
                    }
                    
                    else{
                        c++;
                    }
                    
                    
                }
            }
        }
        return ans;
    }
}