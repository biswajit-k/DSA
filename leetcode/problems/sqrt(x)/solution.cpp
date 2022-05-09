class Solution {
public:
    int mySqrt(int x) {
        double low = 0, high = x, mid, m = x;
	
	for(int i = 0; i < 100; i++)
	{
		mid = (low + high) / double(2.0);
		double res = 1;
		
		for(int j = 0; j < 2; j++)
		{
			res *= mid;
			if(res > m)
				break;
		}
			
		
		if(res == m)
			return mid;
		if(res < m)
			low = mid;
		else 
			high = mid;
	}
	return mid;

    }
};