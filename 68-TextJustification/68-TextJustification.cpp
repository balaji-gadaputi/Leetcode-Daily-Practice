// Last updated: 06/07/2026, 12:00:34
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int n = words.size();
        int i = 0;
        while (i < n) {
            int j = i, charslen = 0;
            while (j < n && charslen + words[j].size() + (j - i) <= maxWidth) {
                charslen += words[j].size();
                j++;
            }
            int count = j - i;
            int spaces = maxWidth - charslen;
            string temp;
            if (j == n || count == 1) {
                temp = words[i];
                for (int k = i + 1; k < j; k++) temp += " " + words[k];
                temp.append(maxWidth - temp.size(), ' ');
            } else {
                int gaps = count - 1;
                int evenspaces = spaces / gaps;
                int extra = spaces % gaps;
                for (int k = i; k < j; k++) {
                    temp += words[k];
                    if (k < j - 1) {
                        temp.append(evenspaces, ' ');
                        if (extra > 0) {
                            temp.push_back(' ');
                            extra--;
                        }
                    }
                }
            }
            res.push_back(temp);
            i = j;
        }
        return res;
    }
};
