class Solution {

private: 

    int find_reach_time(int x, vector<int>& manager, vector<int>& inform_time, vector<int>& reach_time) {

        if(reach_time[x] != -1)
            return reach_time[x];
        
        int my_manager = manager[x];

        return reach_time[x] = inform_time[my_manager] + find_reach_time(my_manager, manager, inform_time, reach_time);
    }

public:

    int numOfMinutes(int n, int head, vector<int>& manager, vector<int>& inform_time) {
        
        vector<int> reach_time(n, -1);
        reach_time[head] = 0;

        int max_time = 0;
        for(int i = 0; i < n; i++)
            max_time = max(max_time, find_reach_time(i, manager, inform_time, reach_time));

        return max_time;
    }
};

/*

    reach_time[head] = 0

    find_reach_time(x):

        if already_calculate_reach_time(x):
            return reach_time[x]

        t = find_reach_time(manager[x])
        reach_time[x] = inform_time[manager[x]] + t

        return reach_time[x]

    // find reach time for each node
    max_time = 0
    for i = 0 to n-1:
        max_time = max(max_time, reach_time[i])
    
    print(max_time)

*/