class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        
        int n = people.size();
        
        auto cmp = [](vector<int>& a, vector<int>& b){
            
            if(a[0] > b[0])
                return true;
            else if(a[0] < b[0])
                return false;
            
            return (a[1] < b[1]);
        };
        
        sort(begin(people), end(people), cmp);
        
        list<vector<int>> lst;
        
        for(auto& person: people)
        {
            auto it = lst.begin();
            advance(it, person[1]);
            
            lst.insert(it, person);
        }
        
        vector<vector<int>> q(n);
        int i = 0;
        
        for(auto& person: lst)
        {
            q[i] = move(person);
            i++;
        }
        
        return q;
    }
};