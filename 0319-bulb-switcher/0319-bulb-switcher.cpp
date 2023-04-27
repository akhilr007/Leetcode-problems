class Solution {
public:
    int bulbSwitch(int n) {
        
        for(int index=1; index*index<=n; index ++){
            
            cout << index * index << " ";
        }
        cout << endl;
        
        return sqrt(n);
    }
};