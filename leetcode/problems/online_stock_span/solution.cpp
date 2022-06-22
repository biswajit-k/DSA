class StockSpanner {
public:

    int i, top;
    pair<int, int> st[int(1e4) + 1];
    
    StockSpanner() {
        i = 0;
        top = -1;
    }
    
    int next(int price) {
        
        int ans = i + 1;
        
        while(top > -1 && st[top].second <= price)
            top--;
        
        if(top > -1) 
            ans = i - st[top].first;
        
        top++;
        st[top] = {i, price};
        i++;
        
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */