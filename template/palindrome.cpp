#include<iostream>
#include<string>


using namespace std;

int main()
{
    int k=0,i=0;
    char st[30];
    cout<<"string: ";
    cin.getline(st,29);
    for(i;st[i];i++);
    cout<<endl;
    for(int j=0;j<=i/2;j++)

    {
        if(st[j]==st[i-j-1])
            k++;
        else break;

    }
  
    if(k==(i/2)+1)
        cout<<"String is a palindrome"<<endl;
    else
        cout<<"string is not a palindrome"<<endl;


    return 0;
}
