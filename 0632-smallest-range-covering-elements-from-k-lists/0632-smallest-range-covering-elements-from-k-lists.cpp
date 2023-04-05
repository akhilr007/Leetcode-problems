// time complexity -> O(klogk) + O(n * klogk)
#define ppi pair<int, pair<int, int>>
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        priority_queue< ppi, vector<ppi>, greater<ppi> > pq; // { value , { list_index, list_value_index}} min heap
        int n = nums.size();

        int maxi = INT_MIN;
        // klogk k ->n
        for(int i=0; i<n; i++){

            int val = nums[i][0];
            int list_index = i;
            int list_value_index = 0;

            maxi = max(maxi, val);
            pq.push({ val, {list_index, list_value_index} });
        }

        vector<int> range(2, 0);
        range[0] = -1e5;
        range[1] = 1e5;

        int rangeDiff = (range[1] - range[0]) ;
        
        // n(max_list_size) * klogk
        while(!pq.empty()){

            auto front = pq.top();
            pq.pop();

            int val = front.first;
            int list_index = front.second.first;
            int list_value_index = front.second.second;

            int newRange = (maxi - val);
            if(newRange < rangeDiff){
                range[0] = val;
                range[1] = maxi;
                rangeDiff = newRange;
            }

            list_value_index++;

            if(list_value_index < nums[list_index].size()){

                    int newVal = nums[list_index][list_value_index];
                    int newListIndex = list_index;
                    int newListValueIndex = list_value_index;

                    maxi = max(newVal, maxi);
                    pq.push({newVal, {newListIndex, newListValueIndex}});

            }
            else break;
        }

        return range;
    }
};