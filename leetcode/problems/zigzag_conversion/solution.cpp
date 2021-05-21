class Solution {
public:
    
string convert(string s, int numRows) {
    string a[numRows];
    int step=0,pos=0;
    for(int i=0;i<(int)s.size();i++)
    {
        a[pos]+=s[i];
        if(pos==numRows-1)
            step=-1;
        else if(pos==0)
            step=1;
        if(numRows==1)
            step=0;
        pos+=step;
    }
    string ans;
    for(int i=0;i<numRows;i++)
        ans+=a[i];
    return ans;     
}

};