class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {

        if(letters.back() <= target)
            return letters[0];

        int l = 0, r = letters.size() - 1;

        while(l < r)
        {
            int mid = (l + r) / 2;

            if(letters[mid] <= target)
                l = mid + 1;
            else 
                r = mid;
        }

        return letters[l];
    }
};