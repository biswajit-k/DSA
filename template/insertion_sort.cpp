#include<bits\stdc++.h>
using namespace std;

int main(){
    int ary[]={6,15,43,5,8,21,19,17890,5,9,7,15};
    for(int i=1;i<(sizeof(ary)/sizeof(7));++i){
        int j=i;
        while(ary[j-1]>ary[j] && j!=0)
        {ary[j-1]+=ary[j];   ary[j]=ary[j-1]-ary[j]; ary[j-1]-=ary[j];   j--;}

    }

    for(int y=0;y<(sizeof(ary)/sizeof(7));++y){
        cout<<ary[y]<<endl;
    }




    return 0;
}