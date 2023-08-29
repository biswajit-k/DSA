class Solution {
public:
    int bestClosingTime(string customers) {

        int n = customers.size();
        int idle_when_open = 0, customer_on_close = 0;

        customer_on_close = count(begin(customers), end(customers), 'Y');

        int min_penalty = n, day = 0;

        for(int i = 0; i < n; i++)
        {
            int curr_penalty = idle_when_open + customer_on_close;
            if(curr_penalty < min_penalty)
            {
                min_penalty = curr_penalty;
                day = i;
            }
            if(customers[i] == 'Y')
                customer_on_close--;
            else 
                idle_when_open++;
        }

        int curr_penalty = idle_when_open + customer_on_close;
        if(curr_penalty < min_penalty)
        {
            min_penalty = curr_penalty;
            day = n;
        }

        return day;
    }
};