#include<iostream>
using namespace std;

int main(){
	int n,m=INT_MAX;
	cin>>n;
	int a[n],b[n+1]={0};

	
	for(int i=0;i<n;++i)
	{
		cin>>a[i];
		
		
	}
	for(int i=0;i<n;++i)
	{	if(a[i]<=n){
		if(b[a[i]]==0 && a[i]>0)	{b[a[i]]=-1;}
	}}
	for(int i=1;i<n+1;++i)
	{
		if(b[i]==0)
			{
				cout<<i;
				
				return 0;
			}
	}
	cout<<n+1;


	return 0;
}
