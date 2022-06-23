class Solution {
public:
    
    static bool comp(const vector<int>& a , const vector<int>& b){
        
        return a[1]<b[1];
    }
    
    int scheduleCourse(vector<vector<int>>& courses) {
        
        sort(courses.begin(), courses.end(), comp);
        
        priority_queue<int> pq;
        int timeElapsed=0;
        
        for(vector<int> course: courses){
            //cout<<course[0]<<" "<<course[1]<<endl;
            if(timeElapsed + course[0] <= course[1]){
                timeElapsed += course[0];
                pq.push(course[0]);
            }
            else if(!pq.empty() and pq.top() > course[0]){
                timeElapsed -= pq.top();
                pq.pop();
                pq.push(course[0]);
                timeElapsed += course[0];
            }
            else{
                // duration > deadline then reject
            }
        }
        
        return pq.size();
    }
};