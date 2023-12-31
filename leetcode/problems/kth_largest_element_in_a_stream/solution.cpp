class KthLargest {
public:

    priority_queue<int, vector<int>, greater<int>> pq;
    int lim;

    KthLargest(int k, vector<int>& A) {

        lim = k;
        for(int i = 0; i < A.size(); i++)
        {
            if(i < k)   pq.push(A[i]);
            else if(A[i] > pq.top())
            {
                pq.pop();
                pq.push(A[i]);
            }
        }
            
    }
    
    int add(int val) {
        if(pq.size() < lim) pq.push(val);
        else if(val > pq.top())
        {
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */