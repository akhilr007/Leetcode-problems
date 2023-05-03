class Solution {
public:
    int optimal(vector<int>& prices, int k){
        
        int n = prices.size();
        vector<vector<int>> ahead(2, vector<int> (k+1, 0));
        vector<vector<int>> cur(2, vector<int> (k+1, 0));
        
        for(int index=n-1; index>=0; index--){
            
            for(int canBuy=0; canBuy<=1; canBuy++) {
                
                // for every cap = 0 , result will be 0 so no point of starting with it
                for(int cap=1; cap<=k; cap++){
                    
                    int profit=0;
                    if(canBuy){
                        int bought = -prices[index] + ahead[0][cap];
                        int notBought = 0 + ahead[1][cap];

                        profit = max(bought, notBought);
                    }
                    else{
                        int sold = prices[index] + ahead[1][cap-1];
                        int notSold = 0 + ahead[0][cap];

                        profit = max(sold, notSold);
                    }

                    cur[canBuy][cap] = profit;
                    
                }
                
                ahead = cur;
            }
        }
        
        return ahead[1][k];
    }
    
    int optimalT(vector<int>& prices, int k){
        
        int n = prices.size();
        
        vector<int> ahead(2*k+1, 0), cur(2*k+1, 0);
        
        for(int index=n-1; index>=0; index--){
            for(int ts=2*k-1; ts>=0; ts--){
                
                int profit = 0;
                if(ts%2 == 0){
                    // buy
                    int bought = -prices[index] + ahead[ts+1];
                    int notBought = 0 + ahead[ts];

                    profit = max(bought, notBought);
                }
                else{
                    // sell
                    int sold = prices[index] + ahead[ts+1];
                    int notSold = 0 + ahead[ts];

                    profit = max(sold, notSold);
                }
                
                cur[ts] = profit;
            }
            ahead = cur;
        }
        
        return ahead[0];
    }
    
    int maxProfit(int k, vector<int>& prices) {
        
        return optimalT(prices, k);
    }
};