class Solution {
public:

    set<string> st;

    void set_invalid_strings(vector<string>& forbidden)
{
    for(auto& s: forbidden)
      {
        reverse(begin(s), end(s));
        st.insert(s);
      }
}

int not_valid_idx(int i, int j, string& word) {

  string curr = "";
  for(int k = j, l = 1; k > i && l < 11; k--, l++)
    {
      curr += word[k];
      if(st.count(curr) != 0)
        return k;
    }
  return -1;
}

    int longestValidSubstring(string word, vector<string>& forbidden) {

      int n = word.length();

      set_invalid_strings(forbidden);

      int len = 0, i = -1, j = 0;

      while(j < n)
        {
          int idx = not_valid_idx(i, j, word);
          if(idx == -1)
          {
            len = max(len, j - i);
          }
          else 
          {
            i = idx;
          }
          j++;
        }

      return len;
    }
};