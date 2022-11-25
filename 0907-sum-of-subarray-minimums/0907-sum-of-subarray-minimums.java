class Solution {
    public int sumSubarrayMins(int[] arr) {
        
        int n = arr.length;
        int[] nsl = new int[n];
        
        Stack<Integer> st = new Stack<>();
        for(int i=0; i<n; i++){
            while(st.size()>0 && arr[st.peek()] >= arr[i]) st.pop();
            
            if(st.size()==0) nsl[i] = -1;
            else nsl[i] = st.peek();
            
            st.push(i);
        }
        
        st.clear();
        
        int[] nsr = new int[n];
        for(int i=n-1; i>=0; i--){
            while(st.size()>0 && arr[st.peek()] > arr[i]) st.pop();
            
            if(st.size()==0) nsr[i] = n;
            else nsr[i] = st.peek();
            
            st.push(i);
        }
        
        long sum=0;
        int MOD = 1000000007;
        
        for(int i=0; i<n; i++){
            long product = (long)arr[i] * ((long)(i-nsl[i])*(nsr[i]-i));
            sum = (sum % MOD + product % MOD) % MOD;
        }
        
        return (int)sum;
    }
}