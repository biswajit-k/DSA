class SnapshotArray {
public:

    int id;
    vector<vector<array<int, 2>>> history;

    SnapshotArray(int length)  {
        this -> id = 0;
        (this -> history).resize(length);
        for(auto& idx: history)
            idx.push_back({0, 0});
    }
    
    void set(int index, int val) {
        auto& idx_history = history[index];

        if((idx_history.back())[0] == id)
            idx_history.back()[1] = val;
        else 
            idx_history.push_back({id, val});
    }
    
    int snap() {
        return id++;
    }
    
    int get(int idx, int snap_id) {
        auto it = lower_bound(begin(history[idx]), end(history[idx]), snap_id, [](auto& a, auto& b) {
            return a[0] <= b;
        });

        it--;

        return (*it)[1];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */