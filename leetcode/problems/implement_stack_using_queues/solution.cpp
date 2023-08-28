class MyStack {

    queue<int> q;
    int top_element;

    int push_back() {
        int x = q.front();
        q.pop();
        q.push(x);
        return x;
    }
    
public:
    MyStack() {
    }
    
    void push(int x) {
        q.push(x);
        top_element = x;
    }
    
    int pop() {
        int sz = q.size();
        for(int i = 0; i < sz - 2; i++)
            push_back();

        if(sz > 1)
            top_element = push_back();

        int x = q.front();
        q.pop();
        return x;
    }
    
    int top() {
        return top_element;
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */