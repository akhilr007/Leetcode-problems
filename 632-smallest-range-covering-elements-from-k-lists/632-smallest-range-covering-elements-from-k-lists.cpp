#define ppi pair<int, pair<int, int>>
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        priority_queue<ppi, vector<ppi>, greater<ppi>> pq;
        // {value, { list_index, data_index }}
        
        int maxi=INT_MIN;
        // insert first element from each row and also calculate the max value b/w them
        for(int i=0; i<nums.size(); i++){
            int val = nums[i][0];
            int li = i;
            int di = 0;
            
            maxi = max(maxi, val);
            pq.push( {val, {li, di } } );
        }
        
        vector<int> range = {-100000, 100000};
        int rangeValue = (range[1]-range[0])+1;
        
        while(pq.size() > 0){
            
            ppi curr = pq.top();
            pq.pop();
            
            int val = curr.first;
            int li = curr.second.first;
            int di = curr.second.second;
            
            int newRange = (maxi - val)+1;
            
            if(newRange < rangeValue){
                rangeValue = newRange;
                range[0] = val;
                range[1] = maxi;
            }
            
            di++;
            
            if(di < nums[li].size()){
                int newVal = nums[li][di];
                int newLi = li;
                int newDi = di;
                maxi = max(maxi, newVal);
                pq.push({newVal, {newLi, newDi}});
            }
            else{
                break;
            }
        }
        
        return range;
    }
};