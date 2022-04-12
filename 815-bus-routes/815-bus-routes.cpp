class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {

        map<int, vector<int>> mp; // bus stop no -> buses

        int n = routes.size(); // no of buses

        for(int i=0; i<n; i++){
            for(int j=0; j<routes[i].size(); j++){
                int busstopno = routes[i][j];
                int busno = i;
                mp[busstopno].push_back(busno);
            }
        }

        queue<int> q;
        unordered_set<int> busStopVis;
        unordered_set<int> busNoVis;

        q.push(source);
        busStopVis.insert(source);

        int level=0;

        while(q.size()>0){

            int size = q.size();

            for(int i=0; i<size; i++){

                int rem = q.front(); q.pop();

                if(rem == target) return level;

                vector<int> buses = mp[rem];

                for(int bus : buses){

                    if(busNoVis.find(bus) != busNoVis.end()){
                        continue;
                    }

                    vector<int> route = routes[bus];

                    for(int busstop : route){

                        if(busStopVis.find(busstop) != busStopVis.end()){
                            continue;
                        }

                        q.push(busstop);
                        busStopVis.insert(busstop);
                    }

                    busNoVis.insert(bus);

                }
            }

            level++;
        }

        return -1;
}
};