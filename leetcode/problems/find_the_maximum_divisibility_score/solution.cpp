class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        
        int n = nums.size(), d = divisors.size();
        
        int div = -1, cnt = -1;
        for(auto& di: divisors)
        {
            int curr = 0;
            for(auto& num: nums)
                if(num % di == 0)
                    curr++;
            if(curr > cnt || (curr == cnt && di < div))
                div = di, cnt = curr;
        }
        
        return div;
    }
};