class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        vector<int> temp;
        temp.push_back(0);
        for(int i=0; i<flowerbed.size(); i++){  
            temp.push_back(flowerbed[i]);
        }
        
        temp.push_back(0);
        
        for(int i=1; i<temp.size()-1; i++){
            
            if(n == 0)
                return true;
            if(temp[i-1] == 0 && temp[i] == 0 && temp[i+1] == 0){
                temp[i] = 1;
                n -= 1;
            }
        }
        
        return n == 0;
    }
};