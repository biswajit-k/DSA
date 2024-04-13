#include<iostream>
using namespace std;
int main(){
    int n,k=0;
    cin>>n;
    while(n!=0){
       
       if(n%10!=0)   k=(k*10)+(n%10);
       
        n=(n-(n%10))/10;

    }
    cout<<k<<endl;


    return 0;
}