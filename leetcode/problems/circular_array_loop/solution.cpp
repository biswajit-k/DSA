class Solution {
		public:
			bool circularArrayLoop(vector<int>& nums) {
				int up=3000,down=-3000,i=0,j=0,temp=0,len=nums.size(),origin=0,pos=0,flag=0;
				for (int i=0;i<len;++i)
				{
					origin=nums[i];//record origin to check the sign 
					temp=nums[i];
					pos=i;
					nums[i]=(origin>0? up :down);
					if (abs(origin)>2000) continue;
					while(1)
					{
						flag=pos; // record the last position
						pos=((pos+temp+1)%len)-1;
						if (pos<0) pos+=len;
						if (pos==flag) break; // jump from i to i, length==1,so break
						temp=nums[pos];
						if (temp*origin<0) break; // opposite sign, break
						if (temp==(origin>0? up : down)) return true; //find the same circle and return true
						if (abs(temp)>2000) break; //find the failed circle id, so we also fail
						nums[pos]= origin>0? up : down;//change the element's value
					}
					if (origin>0) // update the chain id
						up++;
					else
						down--;
				}
				return false;
			}
		};