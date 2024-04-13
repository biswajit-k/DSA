#include<iostream>
#include<string>
using namespace std;
char ch='y';
int k;
void prime();
void fac();
void palin();
int main()
{
       do{

            cout<<"what do you want to check/find--\n 1.check prime number\n 2.find factorial\n 3.check palindrome\n";
            cin>>k;
            switch(k)
            {
            case 1:
                {
                    prime();
                    break;
                }
            case 2:
                {
                    fac();
                    break;
                }
            case 3:
                {
                    palin();
                    break;
                }
            default: cout<<"Not valid\n";


            }
        cout<<"\npress y if want to check/find more";
        cin>>ch;
       }
       while(ch=='y');






    return 0;
}
void prime()
{   cout<<"give the number  ";
    int n;
    cin>>n;
    if(n>0)
    {   int f=0;
        for(int i=2;i<=(n/2)+1;++i)
        {
            if(n%i==0)
            {cout<<"Not a prime\n";
                f=1;
                break;
            }


        }
        if(f==0) cout<<"number is prime\n";
    }
    else cout<<"number not acceptable\n";
}
void fac()
{   cout<<"gine number :  ";
    int n;
    cin>>n;
    if (n>=0)
    {
        int f=1;
        for(int i=1;i<=n;++i)
            f*=i;
        cout<<"the factorial is: "<<f;
        cout<<endl;
    }
    else cout<<"number not acceptable\n";
}
void palin()
{
    cout<<"give the string  ";
    string u;
    cin>>u;
    int l=u.length();
    int t=0;
    for(int i=0,m=l-1;i<=l/2;++i,--m)
    {
        if (u[i]!=u[m])
        {
            cout<<"not a palindrome";
            t=1;
            break;

        }

    }
    if(t==0)
        cout<<"string is a palindrome";

}



