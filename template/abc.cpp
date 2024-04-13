#include<bits/stdc++.h>

using namespace std;


string get_word(string w) {
    string res = "";

    if(w[0] >= 'a' && w[0] <= 'z')
    {
        int i = 0, upper = false;
        while(i < w.length())
        {
            if(w[i] == '_')
                upper = true;
            else 
            {
                res += upper ? 'A' + (w[i] - 'a') : w[i];
                upper = 0;
            }
            i++;
        }
    }
    else 
        res = w;

    return res;
}

string solution(string docstring) {

    string res = "";
    stringstream ss(docstring);

    string word;
    bool convert = false;


    while(ss >> word) {
        res += ' ';

        if(word[0] == '`' && word.back() == '`')
        {
            res += string("`") + get_word(word.substr(1, word.length() - 2)) + "`";
            continue;
        }
        if(word[0] == '`')
        {
            convert = true;
            res += "`";
            word = word.substr(1);
        }
        if(word.back() == '`')
        {
            res += get_word(word.substr(0, word.length() - 1)) + "`";
            convert = false;
            continue;
        }

        if(convert)
            res += get_word(word);
        else 
            res += word;
    }

    return res.substr(1);
}


int main() {

    string s;
    // cin.getline(s);
    getline(cin, s);
    cout << solution(s);

    return 0;
}

/* 

 */