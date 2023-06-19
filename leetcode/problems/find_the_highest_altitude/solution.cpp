class Solution {
public:
    int largestAltitude(vector<int>& gain) {

        int highest_altitude = 0, current_altitude = 0;
        
        for(auto& x: gain)
        {
            current_altitude += x;
            highest_altitude = max(highest_altitude, current_altitude);
        }

        return highest_altitude;
    }
};