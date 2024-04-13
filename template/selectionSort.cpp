#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int ary[n];

    for(int i=0;i<n;++i){
        cin>>ary[i];
    }

    for(int i=0;i<n-1;++i){
        int j=i+1;
        for(int k=i;k<n;++k){
            if(ary[k]<ary[j])  {j=k;}


        }
        ary[i]+=ary[j]; ary[j]=ary[i]-ary[j];   ary[i]-=ary[j];

    }
    for(int& x:ary) {cout<<x<<'\t';}





    return 0;
}