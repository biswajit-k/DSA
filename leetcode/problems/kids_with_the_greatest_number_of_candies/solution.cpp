class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> x;
        for(int i=0;i<candies.size();++i){
            int f=-1;
            for(int j=0;j<candies.size();++j){
                if(candies[i]+extraCandies<candies[j])  {f=0; break;}
                
            }
            if(f==-1)   {x.push_back(1);}
            else    {x.push_back(0);}
        }
        return x;
    }
    
};