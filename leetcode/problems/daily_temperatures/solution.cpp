class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
     
        int n = temp.size();
        vector<int> answer(n, 0);
        
        int st[n], pos = -1;
        
        for(int i = 0; i < n; i++)
        {
            while(pos > -1 && temp[st[pos]] < temp[i])
            {
                answer[st[pos]] = i - st[pos];
                pos--;
            }
            pos++;
            st[pos] = i;
            
        }
        
        return answer;
    }
};