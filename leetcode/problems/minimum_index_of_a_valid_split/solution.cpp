#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumIndex(vector<int>& nums) {

      int n = nums.size();
      set<pair<int, int>> ls, rs;

      unordered_map<int, int> l_freq, r_freq;

      for(auto& x: nums)
      {
        r_freq[x]++;
      }
      for(auto& [v, f]: r_freq)
        rs.insert(make_pair(f, v));

      int idx = n;

      for(int i = 0; i < n - 1; i++)
        {
          int x = nums[i];
          if(l_freq.count(x) == 0)
          {
            l_freq[x]++;
            ls.insert({1, x});
          }
          else
          {
            auto it = ls.find({l_freq[x], x});
            ls.erase(it);
            l_freq[x]++;
            ls.insert({l_freq[x], x});
          }
            
          auto it = rs.find({r_freq[x], x});
          rs.erase(it);
          r_freq[x]--;
          if(r_freq[x] != 0)
            rs.insert({r_freq[x], x});

          auto [l_f, l_v] = *ls.rbegin();
          auto [r_f, r_v] = *rs.rbegin();

          if(l_v == r_v && (l_f * 2 > i + 1) && (r_f * 2) > n - i - 1)
          {
            idx = i;
            break;
          }
          
        }

      return (idx == n ? -1 : idx);
    }
};