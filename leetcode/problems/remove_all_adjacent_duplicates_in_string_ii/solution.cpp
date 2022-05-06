class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        // current character(cur) with frequency(cnt)
        char cur = 'a';
        int cnt = 0;
        
        stack<int> nums;
        
        // result string
        string res = "";
        
        for(auto c: s)
        {
            // add the character
            res += c;
            
            // update current character and frequency
            if(cnt == 0)        // if frequency not set --> set it with current character
            {
                cnt = 1;
                cur = c;
            }
            else if(c == cur)
                cnt++;
            else 
            {
                nums.push(cnt);     // change in current character --> push pervious character frequency in stack
                cnt = 1;
                cur = c;
            }
            
            // remove characters if reached required frequency
            if(cnt == k)
            {
                while(cnt)
                {
                    res.pop_back();
                    cnt--;
                }
                
                // reuse the last stored character in stack as current
                if(!nums.empty())
                {
                    cur = res.back();
                    cnt = nums.top();
                    nums.pop();
                }
                else                    
                    cnt = 0;
                    
            }
                
        }
        
        // return resulting string
        return res;
    }
};