class Solution {
public:
    int minCost(string colors, vector<int>& needed_time) {
        
        int total_time = 0, max_time = 0;
        char curr_color = '0';

        for(int i = 0; i < colors.length(); i++)
        {
            if(colors[i] != curr_color)
            {
                total_time -= max_time;

                curr_color = colors[i];
                max_time = needed_time[i];
            }
            else
                max_time = max(max_time, needed_time[i]);

            total_time += needed_time[i];
        }
        total_time -= max_time;

        return total_time;
    }
};