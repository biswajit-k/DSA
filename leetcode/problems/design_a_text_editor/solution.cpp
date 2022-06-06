class TextEditor {
public:

    list<char> lst;
    list<char>::iterator curr;

    TextEditor() {
        curr = lst.begin();
    }
    
    void addText(string text) {
        for(char c: text)
            curr = lst.insert(curr, c);
    }
    
    int deleteText(int k) {
        int c = 0;
        for(; curr != lst.end() && k; k--, c++)
            curr = lst.erase(curr);

        return c;
    }
    
    string cursorLeft(int k) {
        string res = "";
        for(; curr != lst.end() && k; k--, curr++);

        auto it = curr;
        while(size(res) < 10 && it != lst.end())
            res.push_back(*it), it++;

        reverse(res.begin(), res.end());
        return res;
    }
    
    string cursorRight(int k) {
        string res = "";
        for(; curr != lst.begin() && k; k--, curr--);

        auto it = curr;
        while(size(res) < 10 && it != lst.end())
            res.push_back(*it), it++;

        reverse(res.begin(), res.end());
        return res;
        
    }
};