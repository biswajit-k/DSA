class MedianFinder {

    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;

public:
    MedianFinder() {}

    void addNum(int num) {

        if(left.empty() || num < left.top())
        {
            left.push(num);
            if(left.size() - right.size() > 1)
            {
                right.push(left.top());
                left.pop();
            }
        }
        else
        {
            right.push(num);
            if(right.size() > left.size())
            {
                left.push(right.top());
                right.pop();
            }
        }

    }
    
    double findMedian() {

        double median = left.top();

        if(left.size() == right.size())
            median = (median + right.top()) / 2.0;
        
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */