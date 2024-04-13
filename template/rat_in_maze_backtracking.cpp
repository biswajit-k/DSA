#include<bits/stdc++.h>
#define llint long long int
#define all(v) v.begin(),v.end()
#define fill(a,b)  memset(a,b,sizeof(a))
#define what_is(x) cerr<<#x<<"is"<<x<<'\n';
#define boost std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
bool b[5][5]={},a[][5]={{1,0,0,0,0},{1,0,0,0,0},{1,0,0,0,0},{1,0,0,0,0},{1,1,1,1,1}};

int rat(int x,int y){
    if(x>4 || y>4 || a[x][y]==0)
        return 0;
    if(x==4 && y==4)
        return 1;
    if(rat(x+1,y) || rat(x,y+1))
    {
        b[x][y]=1;
        return 1;
    }
    return 0;
}
// 11
// 22
int main(){
    boost
    b[0][0]=1;  b[4][4]=1;
    rat(0,0);       
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++)
            cout<<b[i][j]<<' ';
        cout<<'\n';
    }
        

    return 0;
}