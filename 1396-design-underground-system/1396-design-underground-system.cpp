class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> mp;
    map<pair<string, string>, vector<int>> st;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        mp[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        if(mp.find(id)!=mp.end()){
            st[{mp[id].first, stationName}].push_back(t-mp[id].second);
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        double time = 0, n = 0;
        if(st.find({startStation, endStation})!=st.end()){
            for(int x : st[{startStation, endStation}]){
                time += x;
                n++;
            }
        }
        
        return time/n;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */