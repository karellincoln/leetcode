class Solution {
public:
    void reverseWord(string &s, int start, int end) {
        while (start < end) {
            char tmp = s[start];
            s[start++] = s[end - 1];
            s[--end] = tmp;
        }
    }

    void reverseWords(string &s) {
        int start = 0, end = 0;
        int pos = 0;
        int i = 0;
        while(true) {
            while (i < s.size() && s[i] == ' ') ++i;
            if (i == s.size()) break;

            start = pos;
            while (i < s.size() && s[i] != ' ') {
                s[pos++] = s[i++];
            }
            end = pos;
            reverseWord(s, start, end);

            if (i == s.size()) break;

            s[pos++] = ' ';
        }

        s.resize(end);
        reverseWord(s, 0, end);
    }
};