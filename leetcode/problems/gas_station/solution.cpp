class Solution {
public:

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n = gas.size();

        int start_idx = 0, reach_idx = (start_idx + 1) % n, fuel = gas[0];

        while(reach_idx != start_idx)
        {
            int reach_cost = cost[(reach_idx - 1 + n) % n];
            while(reach_cost > fuel && start_idx != reach_idx)
            {
                start_idx = (start_idx - 1 + n) % n;
                fuel += gas[start_idx] - cost[start_idx];
            }
            if(reach_cost > fuel)
                return -1;
            
            fuel -= reach_cost;
            fuel += gas[reach_idx];
            reach_idx = (reach_idx + 1) % n;
        }

        return fuel >= cost[(reach_idx - 1 + n) % n] ? start_idx : -1;
    }
};