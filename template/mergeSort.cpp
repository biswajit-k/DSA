#include<bits\stdc++.h>
using namespace std;

void merge(int *ar1,int* ar2,int*ar3,int n,int m){
	int c1=0,c2=0;
	while(c1+c2<m+n){
		if(c1==n){
			ar3[c1+c2]=ar2[c2];
			c2++;
		}
		else if(c2==m){
			ar3[c1+c2]=ar1[c1];
			c1++;
		}
		
		
		else
			if(ar1[c1]>ar2[c2]){
				ar3[c1+c2]=ar2[c2];	
				c2++;

			}
			else{
				ar3[c1+c2]=ar1[c1];
				c1++;

			}
		

	}
	for(int i=0;i<n+m;++i){
		cout<<ar3[i]<<'\t';
	}
}


int main(){
	int n,m;
	cin>>n>>m;

	int*ar1=new int[n];
	int*ar2=new int[m];
	int* ar3=new int[m+n];
	cout<<"give ar1 \n";
	for(int i=0;i<n;++i){
		cin>>ar1[i];
	}	
	cout<<"give ar2 \n";
	for(int i=0;i<m;++i){
		cin>>ar2[i];

	}
	cout<<"ar3 is \n\n";
	merge(ar1,ar2,ar3,n,m);

	


	return 0;
}
