class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int,int> mp;
        vector<int> vec(nums2.size());
        for(int i=0;i<nums2.size();i++)
            mp[nums2[i]]=i;
        vec[nums2.size()-1]=-1;
        s.push(nums2.size()-1);
        for(int i=nums2.size()-2;i>-1;i--)
        {
            while(!s.empty() && nums2[i]>nums2[s.top()])
            {
                s.pop();
            }
            if(s.empty())
            {
                vec[i]=-1;
            }
            else 
                vec[i]=s.top();
            
            s.push(i);
        }
        
        for(int i=0;i<nums1.size();i++)
        {
            nums1[i]=vec[mp[nums1[i]]]==-1?-1:nums2[vec[mp[nums1[i]]]];           
        }
        return nums1;
        
    }
};