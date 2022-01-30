class Solution {
public:
    
    void createSieve(vector<int>& sieve){

        int n=sieve.size();
        
        sieve[0]=sieve[1]=0;
        
        for(long long i=2; i<n; i++){
            if(sieve[i]){
                for(long long j=i*i; j<n; j=j+i){
                    sieve[j]=0;
                }
            }
        }
    }
    
    
    int countPrimes(int n) {
        
        if(n==0 || n==1){
            return 0;
        }
        
        //make sieve arr
        vector<int> sieve(n, 1);
        createSieve(sieve);
        
        // mark count of sieve
        int cnt=0;
        for(int i=2; i<n; i++){
            if(sieve[i]==1){
                cnt++;
            }
        }
        
        return cnt;
        
    }
};