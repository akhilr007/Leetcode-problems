class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        
        //mapping of bus_stop_no with bus_no
        unordered_map<int, vector<int>> m;
        int n = routes.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<routes[i].size(); j++){
               int bus_stop_no = routes[i][j];
               int bus_no = i;
               m[bus_stop_no].push_back(bus_no);
            }
        }

        unordered_set<int> bus_stop_no_vis;
        unordered_set<int> bus_no_vis;

        queue<int> q; // bus_stop_no
        q.push(source);
        bus_stop_no_vis.insert(source);

        int level=-1;

        while(q.size()>0){

            int size = q.size();
            level++;

            for(int i=0; i<size; i++){

                auto rem = q.front();
                q.pop();

                vector<int> buses = m[rem];

                if(rem == target) return level;

                for(int bus : buses){

                    if(bus_no_vis.find(bus) != bus_no_vis.end()){
                        continue;
                    }

                    vector<int> route = routes[bus];

                    for(int bus_stop : route){

                        if(bus_stop_no_vis.find(bus_stop) != bus_stop_no_vis.end()){
                            continue;
                        }

                        q.push(bus_stop);
                        bus_stop_no_vis.insert(bus_stop);
                    }
                    bus_no_vis.insert(bus);
                }
            }
        }

        return -1;
    }
};