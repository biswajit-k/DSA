class Solution {
public:
    
int doit(int from, int now)
{
	if(now <= from)
		return from - now;
	
	if(now % 2 == 0)
		return 1 + doit(from, now / 2);
	else 
		return 1 + doit(from, now + 1);
}

int brokenCalc(int startValue, int target) {
	return doit(startValue, target);
}
};