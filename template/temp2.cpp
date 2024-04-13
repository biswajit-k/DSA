#include<bits/stdc++.h>
#define llint long long int
#define all(v) v.begin(),v.end()
#define Fill(a,b)  memset(a,b,sizeof(a))
#define what_is(x) cerr<<#x<<"is"<<x<<'\n';
#define google cout<<"Case #"<<ll<<": "<<day<<'\n';
#define boost std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
#define mod int(1e9+7)
 
struct P{
    llint x,y;
    void read(){
        cin>>x>>y;
    }
 
    P operator -(const P& b) const{         // p3=p1-p2
        return P{x-b.x,y-b.y};
    }
    long long dot(P& b,P& c){               // a.dot(b,c) find dot product w.r.t a of b and c
        long long x1=b.x-x;
        long long x2=c.x-x;
        long long y1=b.y-y;
        long long y2=c.y-y;
        return (x1*y2-x2*y1);
    }
 
};
bool ifon(P& a,P& b,P& c,P& d)      // if lines are collinear then check if they have point in common
{
    for(int i=0;i<2;i++)
    {
        if(max(a.x,b.x)<min(c.x,d.x) || max(a.y,b.y)<min(c.y,d.y))
            return 0;
        swap(a,c);
        swap(b,d);
    }
    return 1;
}
bool segment_contains(P p1, P p2, P p){
    if(p.dot(p1, p2)) return 0;
    if(max(p1.x, p2.x) < p.x || min(p1.x, p2.x) > p.x) return 0;
    if(max(p1.y, p2.y) < p.y || min(p1.y, p2.y) > p.y) return 0;
    return 1;
}
int main(){
    boost
    int n,m;
    cin>>n>>m;
    P a[n],b[m];
    for(int i=0;i<n;i++)
        a[i].read();
    for(int i=0;i<m;i++)
        b[i].read();
 
    llint count=0;
    for(int i=0;i<m;i++)
    {   
        P p1=b[i],p2{p1.x+1,1000207017};
        int j;
        for(j=0;j<n;j++)
        {
            P p3=a[j],p4=a[j==n-1?0:j+1];
            if(segment_contains(p3,p4,p1))
            {
                cout<<"BOUNDARY\n";
                break;
            }
            P p=p1;
            if(min(p3.x, p4.x) <= p.x && max(p3.x, p4.x) > p.x){
                if(p3.x < p4.x){
                    if(p.dot(p3, p4) < 0) count++;
                }
                else if((p.dot(p4, p3)) < 0) count++;
            }
            
        }
        if(j==n)
        {
            if(count%2==0)
                cout<<"OUTSIDE\n";
            else 
                cout<<"INSIDE\n";
        }
        
    }
    return 0;
}