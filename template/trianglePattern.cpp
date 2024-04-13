#include<iostream>
using namespace std;

int main()
{  int k;
    cout<<"give the number of rows:";
    cin>>k;
    int s=0;

    for(int i=1;i<=k;++i)
    {
    if (i!=k){
     for(int j=1;j<=2*k-1;++j)
     {
         if(j==(k+s) or j==(k-s))
            cout<<'*';
         else cout<<' ';
     }
        s+=1;
    }

    else{
        for(int m=1;m<=2*k-1;++m) cout<<'*';
    }
    cout<<endl;
    }

    return 0;

}
