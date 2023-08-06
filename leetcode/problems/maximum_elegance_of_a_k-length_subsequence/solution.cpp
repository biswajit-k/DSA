class Solution {
public:
    
    typedef long long llint;
    
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        
        int n = items.size();
        unordered_map<int, pair<int, vector<int>>> category_items;
        
        for(auto& vc: items)
        {
            int p = vc[0], c = vc[1];
            category_items[c].first = max(category_items[c].first, p);
            category_items[c].second.push_back(p);
        }
        
        vector<pair<int, vector<int>>> lst;
        for(auto& [_, pr]: category_items)
            lst.push_back(move(pr));
        
        sort(begin(lst), end(lst), greater<pair<int, vector<int>>>());
        
        for(int i = 0; i < lst.size(); i++)
        {
            for(int j = 0; j < lst[i].second.size(); j++)
                if(lst[i].second[j] == lst[i].first)
                {
                    lst[i].second.erase(lst[i].second.begin() + j);
                    break;
                }
        }
        
        llint ans = 0, sum = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i = 0; i < min(k, (int)lst.size()); i++)
        {
            sum += lst[i].first;
            
            if(pq.size() > k - i - 1)
            {
                sum -= pq.top();
                pq.pop();
            }
            
            for(int j = 0; j < lst[i].second.size(); j++)
            {
                sum += lst[i].second[j];
                pq.push(lst[i].second[j]);
                
                if(pq.size() > k - i - 1)
                {
                    sum -= pq.top();
                    pq.pop();
                }
            }
            
            ans = max(ans, sum + (i + 1) * 1LL * (i + 1));
        }
        
        return ans;
    }
};