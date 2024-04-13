 
#include <iostream> 
#include<math.h>
#include<string>						// time = 30 min+
using namespace std; 
int f(int n,int m){
	int carry=0,ans=0,x=0;
	while(n!=0 || m!=0){
		if((n%10)+(m%10)+carry==0)	{carry=0;	}
		else if((n%10)+(m%10)+carry==1)	{carry=0;	ans+=pow(10,x);}
		else if((n%10)+(m%10)+carry==2)	{carry=1;	}
		else if((n%10)+(m%10)+carry==3)	{carry=1;	ans+=pow(10,x);}
		n=n/10;	m=m/10;	x++;
		
	}
	
	ans=ans+carry*(pow(10,x));
	return ans;
}
int main(){
	int n,m;
	cin>>n>>m;
	cout<<endl<<f(m,n);
	



	return 0;
}

