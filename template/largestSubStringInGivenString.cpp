#include<iostream>
using namespace std;


int main()
{
    char st[30];
    char ty[30];
    cout<<"Give 1 string\n";
    cin.getline(st,29);
    cout<<"\ngive 2 string\n";
    cin.getline(ty,29);
    int i=-1,f=-1,p=-1,q=-1;
    int sam[30];
    int h=0;

    for(int l=0;ty[l]!='\0';++l)
    {
        for(int k=0;st[k]!='\0';++k)
        {
            if(ty[l]==st[k])
            {   //cout<<"#";
                p=l;
                q=l;
                for(int j=1;ty[l+j]==st[k+j] and ty[l+j]!='\0' and st[j+k]!='\0';++j)
                {  // cout<<"@";
                    q=l+j;
                }
                if((q-p)>(f-i))
                {
                    f=q;
                    i=p;
                   // cout<<q<<p;

                }
                else if((f-i)==(q-p) and q!=-1)
                    {   //cout<<"$";
                        sam[h]=p;
                        sam[h+1]=q;
                        h=h+2;

                    }


                p=q=-1;

            }


        }

    }


         if(f==-1)
    {
        cout<<"no match found";
    }
        else if(h!=0 and ((sam[1]-sam[0])>(f-i)))
        {
           cout<<"\nfound\n";
           for(int o=0;o<h;o+=2)
           {
               for(int z=sam[o];z<sam[o+1]+1;++z)
                cout<<ty[z];
               cout<<endl;
           }}
        else if(h!=0 and ((sam[1]-sam[0])==(f-i)))
                {
           cout<<"\nfound\n";
           for(int o=0;o<h;o+=2)
           {
               for(int z=sam[o];z<sam[o+1]+1;++z)
                cout<<ty[z];
               cout<<endl;
           }
           cout<<endl;
           for(int m=i;m<f+1;++m)
            {
                cout<<ty[m];
            }}

        else
            {cout<<"\nfound 1\n";
                for(int m=i;m<f+1;++m)
            {
                cout<<ty[m];
            }}




    return 0;
}
