#include<bits/stdc++.h>
#define llint long long int
#define all(v) v.begin(),v.end()
#define boost std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
#define mod int(998244353)

vector<int> pos;
int n;
llint fin=0,cnt=0;
llint fctrl(int x){
    if(x==0)
        return 1;
    llint q=1;
    for(int i=2;i<=x;i++)
        q*=i;
    return q;
}
bool chk(int b,int a){ 

    if(b%a==0)
        for(int i=0;i<int(pos.size());i++)
            if(b/a==pos[i])
                return 1;
    return 0;
}
void solve(int cpos,int* a,llint* ary){
    for(int i=1;i<=fctrl(n-cpos+1);i++)
    {
        if(cpos==n)
            return;
        if(chk(a[cpos],a[cpos-1]))
        {
            fin++;

            solve(cpos+1,a,ary);
            fin--;
        }
        else 
            solve(cpos+1,a,ary);

        if(cpos==n-1)
        {
            ary[fin]++;
            if(ary[fin]>=mod)
                ary[fin]-=mod;
            next_permutation(a,a+n);
            return;
        }
    }
    return;
}


signed main(){
    boost;  
    cin>>n;
    int a[n];
    llint ary[n]={};
    char x;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        if(x=='1')
            pos.push_back(i+1);
        a[i]=i+1;

    }
    llint tot=0;
    solve(1,a,ary);
    
    for(int i=0;i<n;i++)
        cout<<ary[i]<<' ';
    cout<<'\n';
    return 0;
}
