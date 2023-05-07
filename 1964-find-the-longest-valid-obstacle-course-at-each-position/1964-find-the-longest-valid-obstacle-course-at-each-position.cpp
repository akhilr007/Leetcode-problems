class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        
        int n = obstacles.size();
        
        vector<int> temp;
        temp.push_back(obstacles[0]);
        
        vector<int> result(n, 1);
        
        for(int i=1; i<n; i++){
            
            if(obstacles[i] >= temp.back()){
                temp.push_back(obstacles[i]);
                result[i] = temp.size();
            }
            else{
                int index = upper_bound(begin(temp), end(temp), obstacles[i]) - begin(temp);
                temp[index] = obstacles[i];
                result[i] = index+1;
            }
        }
        
        return result;
    }
};