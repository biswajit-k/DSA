#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a=n;
    int b=a+(2*(n-1));
    for(int j=1;j<=n;++j){
        for(int i=1;i<=(4*n)-3;++i){
            if(i==a-j+1 || i==a+j-1 || i==b+j-1 || i==b-j+1){
                cout<<" *";
            }
            else cout<<"  ";
        }
        cout<<endl;
    }




    return 0;
}