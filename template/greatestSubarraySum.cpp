#include<iostream>
#include<typeinfo>
using namespace std;
						//	KADANE'S ALGORITHM ON CIRCULAR ARRAY(FIND MAX SUBARRAY SUM)
						//	I INDEXED TILL 2*N
						//ANOTHER APPROACH IS SUBSTRACT LEAST SUBARRAY SUM FROM TOTAL ARRAY USING KADANE TO GET 
						//ANSWER.

int main(){
	int n;
	cin>>n;
	int a[n];

	
	for(int i=0;i<n;++i)
	{
		cin>>a[i];
	}
	int mx=INT_MIN,curr=0,k=0,ini=0;
	while(k<2*n && k-ini<n)
	{
		if(k<n)
		{
			if(curr+a[k]>0)	{curr+=a[k]; mx=max(mx,curr);	}
			else
			{
				curr=0;	
				ini=k;
			}			

		}
		else
		{
			if(curr+a[k-n]>0)	{curr+=a[k-n]; mx=max(mx,curr);	}
			else
			{
				curr=0;	ini=k;
			}			
		}
		k++;
	}
	cout<<mx;


	

	return 0;
}
