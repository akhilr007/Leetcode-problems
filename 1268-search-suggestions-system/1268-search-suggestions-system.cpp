class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        vector<vector<string>> res;
        
        sort(products.begin(), products.end());
        
        int l=0, r=products.size()-1;
        
        for(int i=0; i<searchWord.length(); i++){
            
            char ch = searchWord[i];
            
            while(l <= r && (products[l].length() <= i || products[l][i] != ch)){
                l++;
            }
            
            while(l <= r && (products[r].length() <= i || products[r][i] != ch)){
                r--;
            }
            
            vector<string> ans;
            
            int remaining = r-l+1;
            
            for(int j=0; j<min(3, remaining); j++){
                ans.push_back(products[l+j]);
            }
            
            res.push_back(ans);
        }
        
        return res;
    }
};