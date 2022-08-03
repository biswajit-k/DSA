class MyCalendar {
public:
    
    map<int, int> mp;
    
    MyCalendar() {
        
    }
    
    bool book(int s, int e) {
        
        auto nxt = mp.lower_bound(s);
        
        if(nxt != mp.end() && nxt -> first < e) return false;
        
        if(nxt != mp.begin() && s < (--nxt) -> second) return false;
        
        mp[s] = e;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */