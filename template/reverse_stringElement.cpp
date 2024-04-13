#include<iostream>
using namespace std;
int main()
{
    char st[30];
    char sa[30];
    int len=0;
    cout<<"give:";
    cin.getline(st,29);
    for (int i=0;st[i]!='\0';++i,++len);
    int i=0,f=0;


    for(int m=0;m<len;++m)
    {
        if(st[m]!=' ')
        {
            f=m;

        }
        else
        {
            for(int q=f;q>=i;--q)
            {
                cout<<st[q];
            }
        cout<<' ';
        i=f+2;
        f=i;
        }
        if(m==len-1)
        {
            for(int q=f;q>=i;--q)
            {
                cout<<st[q];
            }
        }


    }






    return 0;
}


