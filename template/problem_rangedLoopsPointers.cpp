
#include <iostream> 
#include<string>

using namespace std; 

int main() 
{ 	char a[]="hello";
	string b="hello";
	if(b==a)	cout<<*(a+4);
	int* ary=new int[3];
	ary[0]=ary[1]=ary[2]=6;
	cout<<ary;
	for(int& x :*ary){		//	some problem with decaying ? Using pointers in ranged loops instead of pointers
		cout<<x<<endl;
	}


	
	return 0; 
} 
