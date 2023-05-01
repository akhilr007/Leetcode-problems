class Solution {
public:
    double average(vector<int>& salary) {
        
        int maxi = INT_MIN;
        int mini = INT_MAX;
        
        for(int i=0; i<salary.size(); i++)
        {
            maxi = max(maxi, salary[i]);
            mini = min(mini, salary[i]);
        }
        
        int sum = 0;
        int cnt = 0;
        
        for(int i=0; i<salary.size(); i++)
        {
            if(salary[i] == maxi || salary[i] == mini)
                continue;
            
            sum += salary[i];
            cnt ++;
        }
        
        
        double average = (sum * 1.0) / cnt;
        
        return average;
    }
};