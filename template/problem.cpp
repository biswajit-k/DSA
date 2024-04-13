#include<iostream>
#include<string>
//INFIX TO POSTFIX SEGMENTATION FAULT

using namespace std;
string itp(string st)
{
    string x="",kt="";
    for(int i=0;i<st.size();++i)
    {
        if(st[i]=='(')
            x.push_back('(');
        
        else if(st[i]==')')
        {   
            for(int k=x.size()-1;x[k]!='(';k--)
            {
                kt.push_back(x[k]);
                x.pop_back();
                
            }
            x.pop_back();
        }
        else if(x.back()=='(') 
                x.push_back(st[i]);
        else if(st[i]=='^')
        {
            while(x.back()=='^' || x.back()=='(')
                {
                    kt.push_back(x.back());
                    x.pop_back();
                }
                x.push_back('^');
            
        }
        else if(st[i]=='/')
        {
            while(x.back()=='^' || x.back()=='(' || x.back()=='/')
                {
                    kt.push_back(x.back());
                    x.pop_back();
                }
                x.push_back('/');
        }
        else if(st[i]=='*')
        {
            while(x.back()=='^' || x.back()=='(' || x.back()=='/' || x.back()=='*')
                {
                    kt.push_back(x.back());
                    x.pop_back();
                }
                x.push_back('*');
        }
        else if(st[i]=='+')
        {
            while(x.back()!='-' || x.back()=='(' || x.back()=='+')
                {
                    kt.push_back(x.back());
                    x.pop_back();
                }
                x.push_back('+');
        }
        else if(st[i]=='-')
        {
            while(x.back()=='-' || x.back()=='(')
                {
                    kt.push_back(x.back());
                    x.pop_back();
                }
                x.push_back('-');
        }
        else
            kt.push_back(st[i]);
        
    }
    while(x.back()!=0)
    {
        
    
        kt.push_back(x.back());
        x.pop_back();
        
    
    }
    return kt;
    
}
int main()
{
    int n;
    cin>>n;
    string s;
    for(int j=0;j<n;++j)
    {
        cin>>s;
        cout<<itp(s);
        cout<<endl;
    }
    return 0;
}