class MyQueue {

private:

    stack<int> s1, s2;
    int s1_front;
    bool reversed;

public:

    MyQueue(): reversed(false) {}
    
    void push(int x) {
        s1.push(x);
        if(s1.size() == 1)  s1_front = x;
    }
    
    int pop() {
        int x = this -> peek();
        if(reversed)
            s2.pop();
        else 
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            if(!s2.empty()) 
                s2.pop();
        }

        reversed = s2.empty() ? false : true;

        return x;
    }
    
    int peek() {
        if(!s2.empty()) return s2.top();
        return s1_front;
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
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