class SmallestInfiniteSet {
public:

    int infinite_pointer;
    set<int> st;

    SmallestInfiniteSet() {
        infinite_pointer = 1;
    }
    
    int popSmallest() {
        int res;
        if(!st.empty())
        {
            res = *st.begin();
            st.erase(st.begin());
        }
        else 
            res = infinite_pointer++;
        return res;
    }
    
    void addBack(int num) {
        if(num < infinite_pointer)
            st.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */