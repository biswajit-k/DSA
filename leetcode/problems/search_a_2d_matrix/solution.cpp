class Solution {
public:

	int bsearch(vector<int>& a, int x){
		int l = 0, r = int(a.size()) - 1;
		while(l < r){
			int mid = l + (r - l) / 2;
			if(a[mid] == x) return mid;	
			if(a[mid] < x) l = mid + 1;		
			else r = mid - 1;
		}return (a[l] == x ? l : -1);
	}

	int dsearch(vector<vector<int>>& matrix, int target) {

		int l = 0, r = matrix.size() - 1, ans = 0;

		while(l <= r)
		{
			int mid = (l + r) / 2;

			if(matrix[mid][0] == target)
				return mid;
			if(matrix[mid][0] > target)
				r = mid - 1;
			
			else 
			{
				ans = mid;
				l = mid + 1;
			}
			
		}
		return ans;
	}

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();

		if(target > matrix[n -1][m - 1])
			return 0;
		
		int pos = dsearch(matrix, target);
		if(bsearch(matrix[pos], target) == -1)
			return 0;
		
		return 1;
    }
};