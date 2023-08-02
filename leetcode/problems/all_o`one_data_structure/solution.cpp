class AllOne {

    unordered_map<int, list<pair<string, int>>> freq_list;
    unordered_map<string, list<pair<string, int>>::iterator> key_it;

    list<int> freq;
    unordered_map<int, list<int>::iterator> freq_it;

    void insert_key(string k, int f) {
        if(f > 0) {
        freq_list[f].push_front(make_pair(k, f));
        key_it[k] = freq_list[f].begin();
        }
    }
    void remove_key(string k) {
        if(key_it.count(k)) {
            auto it = key_it[k];
            int f = it -> second;
            freq_list[f].erase(it);
            if(freq_list[f].empty())
                freq_list.erase(f);
            key_it.erase(k);
        }
    }

public:
    AllOne() {}
    
    void inc(string key) {
        int f = key_it.count(key) ? key_it[key] -> second : 0;
        remove_key(key);
        if(freq_it.count(f + 1) == 0)
        {
            auto pos = f ? next(freq_it[f]) : freq.begin();
            freq_it[f + 1] = freq.insert(pos, f + 1);
        }
        if(freq_list.count(f) == 0 && f > 0)
        {
            freq.erase(freq_it[f]);
            freq_it.erase(f);
        }
        insert_key(key, f + 1);
    }
    
    void dec(string key) {
        int f = key_it[key] -> second;
        remove_key(key);

        if(f > 1 && freq_it.count(f - 1) == 0)
            freq_it[f - 1] = freq.insert(freq_it[f], f - 1);
        if(freq_list.count(f) == 0)
        {
            freq.erase(freq_it[f]);
            freq_it.erase(f);
        }
        insert_key(key, f - 1);

    }
    
    string getMaxKey() {
        if(freq.empty())
            return "";
        return freq_list[freq.back()].back().first;
    }
    
    string getMinKey() {
        if(freq.empty())
            return "";
        return freq_list[freq.front()].back().first;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */