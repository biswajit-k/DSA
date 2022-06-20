class MyQueue {
public:
    stack<int> s, tp;
    int top;
    
    MyQueue() {}
    
    void push(int x) {
        s.push(x);
        if(s.size() == 1)
            top = x;

    }
    
    int pop() {
        int x;
        while(!s.empty())
        {
            tp.push(s.top());
            s.pop();
        }
        x = tp.top();
        tp.pop();
        if(!tp.empty())
            top = tp.top();
        while(!tp.empty())
        {
            s.push(tp.top());
            tp.pop();
        }
        return x;
    }
    
    int peek() {
        return top;
    }
    
    bool empty() {
        return s.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */