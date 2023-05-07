class FrequencyTracker {
public:
    const int N = 1e5 + 1;
    vector<int> num, freq;
    
    FrequencyTracker() {
        num.resize(N, 0);
        freq.resize(N, 0);
    }
    
    void add(int number) {
        num[number]++;
        int cnt = num[number];
        if(cnt == 1)
            freq[1]++;
        else 
        {
            freq[cnt - 1]--;
            freq[cnt]++;
        }
    }
    
    void deleteOne(int number) {
        if(num[number])
        {
            num[number]--;
            int cnt = num[number];
            freq[cnt + 1]--;
            if(cnt > 0) freq[cnt]++;
        }
    }
    
    bool hasFrequency(int f) {
        return freq[f] > 0;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */