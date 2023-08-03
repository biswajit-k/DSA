class AllOne {


    class Bucket {
        
        public:

        int frequency;
        unordered_set<string> keys;

        Bucket(): frequency(0) {}
        Bucket(int f): frequency(f) {}

    };


    list<Bucket> frequencies;
    unordered_map<int, list<Bucket>::iterator> bucket_by_frequency;
    unordered_map<string, int> key_freq; 

    void decrease_freq(string k) {

        int f = key_freq[k];

        key_freq[k] = f - 1;


        if(f > 1)      // insert only if freq exist
        {
            // create bucket if not exist
            if(bucket_by_frequency.find(f - 1) == bucket_by_frequency.end())
            {
                // create and insert before f
                bucket_by_frequency[f - 1] = frequencies.insert(bucket_by_frequency[f], Bucket(f - 1));
            }
            
            bucket_by_frequency[f - 1] -> keys.insert(k);
        }

        // remove from bucket and erase bucket if got empty
        bucket_by_frequency[f] -> keys.erase(k);
        if(bucket_by_frequency[f] -> keys.empty())
        {
            auto it = bucket_by_frequency[f];
            bucket_by_frequency.erase(f);
            frequencies.erase(it);
        }
    }

    void increase_freq(string k) {

        // what is the frequency - update frequency
        int f = key_freq[k];
        key_freq[k] = f + 1;

        // create next bucket if not exist and insert
        if(bucket_by_frequency.find(f + 1) == bucket_by_frequency.end())
        {
            auto pos = f ? next(bucket_by_frequency[f]) : frequencies.begin();
            bucket_by_frequency[f + 1] = frequencies.insert(pos, Bucket(f + 1));       // check where to insert
        }

        bucket_by_frequency[f + 1] -> keys.insert(k);

        // remove from previous if previous > 0 and erase bucket if got empty
        if(f > 0)
        {
            auto& prev_bucket = *bucket_by_frequency[f];
            prev_bucket.keys.erase(k);
            if(prev_bucket.keys.empty())
            {
                auto it = bucket_by_frequency[f];
                bucket_by_frequency.erase(f);
                frequencies.erase(it);
            }
        }
    }


public:
    AllOne() {}
    
    void inc(string key) {
        if(key_freq.find(key) == key_freq.end())
            key_freq[key] = 0;

        increase_freq(key);
    }
    
    void dec(string key) {
        decrease_freq(key);
    }
    
    string getMaxKey() {
        if(frequencies.empty())
            return "";
        return *(frequencies.back().keys.begin());
    }
    
    string getMinKey() {
        if(frequencies.empty())
            return "";
        return *(frequencies.front().keys.begin());
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