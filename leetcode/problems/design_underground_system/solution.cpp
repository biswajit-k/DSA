class UndergroundSystem {

private:
    unordered_map<int, pair<string, int>> customer;
    map<pair<string, string>, pair<int, int>> travel;

public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string name, int t) {
        customer[id] = {name, t};
    }
    
    void checkOut(int id, string name, int t) {
        auto [d_name, start] = customer[id];
        customer.erase(id);

        auto visit = make_pair(d_name, name);
        auto [time, times] = travel[visit];
        time += t - start;

        travel[visit] = {time, times + 1};
    }
    
    double getAverageTime(string d_name, string a_name) {
        auto [time, times] = travel[make_pair(d_name, a_name)];
        return double(time) / double(times);   
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */