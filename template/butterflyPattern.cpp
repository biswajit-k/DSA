#include<iostream>
using namespace std;
void upper(int);
void lower(int);
int main(){
    int n;
    cin>>n;
    if(n%2==0){
        upper(n/2); lower(n/2);

    }
    else{
        upper((n/2)+1); lower(n/2);
    }


    return 0;
}

void upper(int r){
    for(int m=1;m<=(r);++m){
        for(int j=1;j<=(2*r);++j){
            if(j>m && j<(2*r)-m+1){
            cout<<' ';
        }
        else cout<<'*';
        }
        cout<<endl;
    }
}
void lower(int r){
    for(int m=r;m>=1;--m){
        for(int j=1;j<=(2*r);++j){
            if(j>m && j<(2*r)-m+1){
            cout<<' ';
        }
        else cout<<'*';
        }
        cout<<endl;
    }

}