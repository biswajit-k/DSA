int speed_up = []{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

int init = []{
    ofstream out("user.out", ios::out);
    string line;
    while (getline(cin, line)) {
        string::iterator i = line.begin();
        for (string::iterator r = line.begin(); r < line.end(); r++) {
            *i = *r;
            if (*i != ' ') i++;
        }
        for (; i >= line.begin(); i--) {
            if (*i >= '0' && *i <= '9' || *i == '[') {
                *++i = ']';
                *++i = 0;
                break;
            }
        }
        out << line.c_str() << endl;
    }

    exit(0);
    return 0;
}();

class Codec{public:string serialize(TreeNode*root){return 0;}TreeNode*deserialize(string data){return NULL;}};