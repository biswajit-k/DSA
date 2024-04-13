#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#define llint long long int
#define boost std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
void tbn(llint x,vector<int>& bx){
    while(x!=0)
    {
        bx.push_back(x%2);
        x=x/2;
    }
    reverse(bx.begin(),bx.end());
    if((int)bx.size()<30)
        bx.insert(bx.begin(),30-(int)bx.size(),0);
    
}

int main(){
    boost;
    int t;
    llint x,y,n;
    cin>>t;
    while(t--)
    {
        cin>>x>>y>>n;
        vector<int> bx,by,bn;
        int ctr=0;
        tbn(x,bx);  tbn(y,by);  tbn(n,bn);
        int i=1;
        while(i<=n)
        {
            vector<int> m;
            tbn(i,m);
            for(int j=0;j<30;j++)
            {
                if((bx[j]^m[j])<(by[j]^m[j]))
                {
                    ctr+=pow(2,30-j-1)+1;
                    i+=pow(2,30-j-1);
                   // cout<<"num"<<i<<'\n';
                    break;
                }
                else if((bx[j]^m[j])>(by[j]^m[j]))
                {   i+=pow(2,30-j-1);
                    break;
                }
            }
            i++;
        }
        if((x^0)<(y^0))
            ctr++;
        cout<<ctr<<'\n';

    }
    return 0;
}
