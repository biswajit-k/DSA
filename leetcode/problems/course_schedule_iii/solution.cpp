
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        
        int count = 0, time = 0, n = courses.size();

        priority_queue<int> pq;

        auto cmp = [](vector<int>& c1, vector<int>& c2){
            return c1[1] < c2[1];
        };

        sort(begin(courses), end(courses), cmp);

        for(int i = 0; i < n; i++)
        {
            int end = courses[i][1], d = courses[i][0];

            pq.push(d);
            time += d;
            count++;

            if(time > end)
            {
                int duration = pq.top();
                pq.pop();
                count--;
                time -= duration;
            }

        }

        return count;

    }
};