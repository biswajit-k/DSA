#include<bits\stdc++.h>

using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a;
    a.push_back(1);
    
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n-i;++j){
            cout<<" ";

        }
        vector<int> b;
        b.push_back(1);
        for(int m=1;m<=(i);++m){
            cout<<a[m-1]<<" ";
            if(i>=2 && m!=(i)){
                b.push_back(a[m-1]+a[m]);
            }
        }
        b.push_back(1);
        
        a=b;
        cout<<endl;

        cout<<endl;
    }



    return 0;
}