#include<bits/stdc++.h>
#define llint long long int
#define all(v) v.begin(),v.end()
#define fill(a,b)  memset(a,b,sizeof(a))
#define what_is(x) cerr<<#x<<"is"<<x<<'\n';
#define boost std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
/*Given a binary tree which has T nodes, you need to find the diameter of that binary tree. The diameter of a tree is the number of nodes on the longest path between two leaves in the tree.

Input:
First line contains two integers, T and X, number of nodes in the tree and value of the root.
Next  lines contain details of nodes.
Each detail of node contains two lines. First lines contains a string and second line contains an integer, which denotes the path of the node and the value of the node respectively.

String consists of only L or R. L denotes left child and R denotes right child. ( Look at the sample explanation for more details )

Output:
Print the diameter of the binary tree.*/

llint calc(string s1,string s2){        // function to calculate max length from one node to other in bst
    if(s1==s2)
        return 1;
    
    if(s1.length()>s2.length())
    {
        return 1+calc(s1.substr(0,s1.length()-1),s2);
    }
    else 
    {
        return 1+calc(s2.substr(0,s2.length()-1),s1);
    }

}

int main(){
    boost
    int t,x,faltu;
    cin>>t>>x;
    vector<string> left,right;

    for(int i=0;i<t-1;i++)
    {
        string sample;
        cin>>sample>>faltu;
        left.emplace_back(sample);
    }
    llint maxlen=1;
    for(int i=0;i<int(left.size())-1;i++)
    {
        for(int j=i+1;j<(int)left.size();j++)
        {
            maxlen=max(maxlen,calc(left[i],left[j]));
        }
    }
    cout<<maxlen<<'\n';


   return 0;
}