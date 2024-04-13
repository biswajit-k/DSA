#include<iostream>
using namespace std;
int main(){
    int a[]={[0...3]=1};
  //  int a[][]={[0...1][0...1]={INT_MAX,INT_MIN}};
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            cout<<a[i][j]<<' ';
        }
        cout<<endl;
    }



    return 0;
}