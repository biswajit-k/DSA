class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        int boats = 0, first = 0, last = people.size() - 1;
        sort(people.begin(), people.end());
        
        while(first <= last)
        {
            boats++;
            last--;
            if(first > last)
                break;
            if(people[first] + people[last + 1] <= limit)
                first++;
        }
        
        
        
        return boats;
    }
};